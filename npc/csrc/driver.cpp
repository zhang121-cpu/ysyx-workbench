#include "npc_api.h"
#include "Vtop.h"
#include <verilated.h>

#ifdef CONFIG_WAVE_RECORD
#include <verilated_fst_c.h>
#endif

//设置3全局变量以供使用(nullptr在C++中类似NULL在C中，表示空指针)
VerilatedContext *contextp = nullptr;
Vtop *top = nullptr;
#ifdef CONFIG_WAVE_RECORD
VerilatedFstC *tfp = nullptr;    //波形文件对象
#endif

//仿真控制的创立
static void filestart(int argc, char** argv){
    contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);
    top = new Vtop{contextp};
}

#ifdef CONFIG_WAVE_RECORD
static void init_wavefile(const char *log_file) {
    // 启用跟踪
    contextp->traceEverOn(true);              

    // 创建波形文件对象
    tfp = new VerilatedFstC;   // FST 格式

    // 将 top 模块的信号写入波形，跟踪深度为 99（跟踪深度：从顶层模块开始向下追踪多少层子模块的信号）
    top->trace(tfp, 99);

    //推导 build 目录, 把文件写到 .../build/wave.fst
    char path[256];
    strcpy(path, log_file);
    char *slash = strrchr(path, '/');          // 找最后一个 '/'
    strcpy(slash + 1, "wave.fst");  // 替换文件名

    tfp->open(path);      
    //想写一点日志信息的，但总是报错，有缘者可以帮忙把这个问题处理一下
    // Assert(tfp, "Can not open wave '%s'", path);
    // Log("wave is written to %s", path);
}

void init_wave(const char *log_file) {
    if (log_file == NULL) return;
    init_wavefile(log_file);
}

static void end_wave() {
    tfp->close();
    delete tfp;
}
#endif

//结束仿真控制
static void fileend() {
    delete top;
    delete contextp;
}

int main(int argc, char **argv) {
    filestart(argc, argv);
    npc_reset(10);              //在init_monitor中应该已经有复位措施，这里重复一遍是在是init_monitor函数以及芯片复位逻辑都没法改变
    init_monitor(argc, argv);
#ifdef CONFIG_WAVE_RECORD
    npc_wave_record();                 // 记录复位后的第一个周期的波形,后续的记录都靠exec_once()函数了
#endif
    engine_start();             /* -b 时直接 cpu_exec(-1) 跑到底 */
    int bad = is_exit_status_bad();
#ifdef CONFIG_WAVE_RECORD
    end_wave();
#endif
    fileend();
    return bad;
}