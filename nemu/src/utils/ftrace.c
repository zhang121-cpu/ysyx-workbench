#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <elf.h>
#include <common.h>

// 存储函数信息的结构体
typedef struct {
    uint32_t addr;    // 函数起始地址
    uint32_t size;    // 函数大小（字节）
    char name[64];    // 函数名
} FuncInfo;

#define MAX_FUNCS 256
static FuncInfo func_table[MAX_FUNCS];
static int func_count = 0;

// ---- 新增：ftrace 专属日志文件 ----
static FILE *ftrace_fp = NULL;   // ftrace 输出目标
static int call_depth = 0;        // 调用深度（缩进用）

// 根据 elf 文件路径推导 build 目录，打开日志文件
// .../build/add.elf  →  .../build/nemu-log-ftrace.txt
static void init_ftrace_log(const char *elf_file) {
    char path[256];
    strcpy(path, elf_file);
    char *slash = strrchr(path, '/');          // 找最后一个 '/'
    strcpy(slash + 1, "nemu-log-ftrace.txt");  // 替换文件名
    ftrace_fp = fopen(path, "w");
    Assert(ftrace_fp, "Can not open ftrace log '%s'", path);
    Log("ftrace log is written to %s", path);
}

// 初始化 ftrace：读取 ELF 文件，提取函数符号
void init_ftrace(const char *elf_file) {
    if (elf_file == NULL) {
        Log("ftrace函数: elf_file is NULL, ftrace功能将被禁用");
        return;
    }

    init_ftrace_log(elf_file);   // ← 先打开日志文件
    
    FILE *fp = fopen(elf_file, "rb");
    Assert(fp, "Can not open ELF file '%s'", elf_file);
    
    // ---- 读取 ELF 头 ----
    Elf32_Ehdr ehdr;  // ELF 头结构体（来自 <elf.h>）
    Assert(fread(&ehdr, sizeof(ehdr), 1, fp) == 1, "读取 ELF 头失败");
    
    // ---- 读取节头表 ----
    // ehdr.e_shnum = 节的数量
    // ehdr.e_shoff = 节头表在文件中的偏移
    Elf32_Shdr shdr[ehdr.e_shnum];
    fseek(fp, ehdr.e_shoff, SEEK_SET);
    Assert(fread(shdr, sizeof(Elf32_Shdr), ehdr.e_shnum, fp) == ehdr.e_shnum,
        "读取节头表失败");
    
    // ---- 读取 .shstrtab（节名字符串表）----
    // ehdr.e_shstrndx = .shstrtab 在节头表中的索引
    char shstrtab[shdr[ehdr.e_shstrndx].sh_size];
    fseek(fp, shdr[ehdr.e_shstrndx].sh_offset, SEEK_SET);
    Assert(fread(shstrtab, shdr[ehdr.e_shstrndx].sh_size, 1, fp) == 1,
        "读取 .shstrtab 失败");
    
    // ---- 找到 .symtab 和 .strtab 的索引 ----
    int symtab_idx = -1, strtab_idx = -1;
    for (int i = 0; i < ehdr.e_shnum; i++) {
        char *name = shstrtab + shdr[i].sh_name;  // 节名
        if (strcmp(name, ".symtab") == 0) symtab_idx = i;
        if (strcmp(name, ".strtab") == 0) strtab_idx = i;
    }
    Assert(symtab_idx >= 0, "ELF file has no .symtab section");
    Assert(strtab_idx >= 0, "ELF file has no .strtab section");
    
    // ---- 读取字符串表 ----
    char *strtab = malloc(shdr[strtab_idx].sh_size);
    fseek(fp, shdr[strtab_idx].sh_offset, SEEK_SET);
    Assert(fread(strtab, shdr[strtab_idx].sh_size, 1, fp) == 1,
        "读取 .strtab 失败");
    
    // ---- 遍历符号表，提取函数符号 ----
    int sym_count = shdr[symtab_idx].sh_size / sizeof(Elf32_Sym);
    fseek(fp, shdr[symtab_idx].sh_offset, SEEK_SET);
    
    for (int i = 0; i < sym_count; i++) {
        Elf32_Sym sym;
        Assert(fread(&sym, sizeof(Elf32_Sym), 1, fp) == 1, "读取符号表失败");
        
        // ELF32_ST_TYPE(sym.st_info) 获取符号类型
        // STT_FUNC 表示函数符号
        if (ELF32_ST_TYPE(sym.st_info) == STT_FUNC) {
            Assert(func_count < MAX_FUNCS, 
                "ftrace出错:函数数量超过 %d,请修改nemu/src/utils/ftrace中MAX_FUNCS的值", MAX_FUNCS);
            func_table[func_count].addr = sym.st_value;
            func_table[func_count].size = sym.st_size;
            strcpy(func_table[func_count].name, strtab + sym.st_name);
            func_count++;
        }
    }
    
    free(strtab);
    fclose(fp);
    
    Log("ftrace: 已从 %s 已加载 %d 个函数", elf_file, func_count);
}

// 根据地址查找函数名
const char* find_func_name(uint32_t addr) {
    for (int i = 0; i < func_count; i++) {
        if (addr >= func_table[i].addr && 
            addr < func_table[i].addr + func_table[i].size) {
            return func_table[i].name;
        }
    }
    return "查找不到函数名";
}


// ---- 新增：写入 ftrace 日志文件 ----
void ftrace_call(uint32_t pc, uint32_t target) {
    if (ftrace_fp == NULL) {
        return;
    }
    fprintf(ftrace_fp, "0x%08x: ", pc);
    for (int i = 0; i < call_depth; i++) fprintf(ftrace_fp, "  ");
    fprintf(ftrace_fp, "call [%s@0x%08x]\n", find_func_name(target), target);
    fflush(ftrace_fp);
    call_depth++;
}

void ftrace_ret(uint32_t pc) {
    if (ftrace_fp == NULL) {
        return;
    }
    if (call_depth > 0) call_depth--;
    fprintf(ftrace_fp, "0x%08x: ", pc);
    for (int i = 0; i < call_depth; i++) fprintf(ftrace_fp, "  ");
    fprintf(ftrace_fp, "ret  [%s]\n", find_func_name(pc));
    fflush(ftrace_fp);
}
