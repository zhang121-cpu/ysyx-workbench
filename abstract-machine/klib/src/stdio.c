#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

#define BUF_SIZE 32
#define OUTPUT_BUF_SIZE 1024

//将可变参数按照 fmt 格式化输出到终端中，返回写入的字符数（不含 \0）
int printf(const char *fmt, ...) {
  char out[OUTPUT_BUF_SIZE];
  va_list ap;
  va_start(ap, fmt);
  int ret = vsprintf(out, fmt, ap);  
  va_end(ap);
  for (char *p = out; *p; p++) {
    putch(*p);
  }
  return ret;
}

//将可变参数按照 fmt 格式化输出到 out 中，返回写入的字符数（不含 \0）
int vsprintf(char *out, const char *fmt, va_list ap) {
  return vsnprintf(out, (size_t)-1, fmt, ap);   // 长度无限,等于不截断
}

//将可变参数按照 fmt 格式化输出到 out 中，返回写入的字符数（不含 \0）
//与vsprintf不同的是，sprintf使用...而不是va_list
int sprintf(char *out, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int ret = vsprintf(out, fmt, ap);
  va_end(ap);
  return ret;
}

//将可变参数按照 fmt 格式化输出到 out 中，返回本应写入的字符数（不含 \0）
//此外，snprintf() 函数提供了一个参数 size，如果格式化后的字符串长度超过了 size-1
//则 snprintf() 只会写入 size-1 个字符，并在字符串的末尾添加一个空字符（\0）以表示字符串的结束
int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  char *p = out;
  size_t left = (n > 0) ? n - 1 : 0;   // 最多写 left 个字符,末尾留 \0
  int total = 0;                       // 记录"本来会写多少"

  #define PUT(c) do { total++; if (left > 0) { *p++ = (c); left--; } } while (0)

  while (*fmt) {
    if (*fmt == '%') {
      fmt++;                                          // 跳过 %
      switch (*fmt) {
        case 'd': {                              // 整数
          int num = va_arg(ap, int);
          char buf[BUF_SIZE];
          itoa(num, buf, 10);       // 将整数转换为字符串
          char *s = buf;                    // 工作指针指向 buf，避免后面buf无法自增的问题
          while (*s) PUT(*s++);
          fmt++;
          break;
        }
        case '0': {                               // %0Nd:零填充宽度
          int width = 0;
          while (*fmt >= '0' && *fmt <= '9') {    // 解析宽度 N
            width = width * 10 + (*fmt - '0');
            fmt++;
          }
          if (*fmt == 'd') {                      // 只支持 %0Nd
            int num = va_arg(ap, int);
            char buf[BUF_SIZE];
            itoa(num, buf, 10);
            int len = 0;
            while (buf[len]) len++;               // 数字位数
            while (len++ < width) PUT('0');       // 左边补 0
           char *s = buf;                    // 工作指针指向 buf，避免后面buf无法自增的问题
            while (*s) PUT(*s++);
            fmt++;
          }
          break;
        }
        case 'c':{                                 // 字符
          PUT((char)va_arg(ap, int));    //c语言中...会默认对char进行int类型的提升
          fmt++;
          break;
        }
        case 's':{                                 // 字符串
          char *s = va_arg(ap, char *);
          if (s == NULL) 
            panic("空指针!");            // NULL不能读取内容，如果字符串为 NULL，则报错
          while (*s) PUT(*s++);
          fmt++;
          break;
        }
        case '%':{                                 // 字符 %
          PUT('%');
          fmt++;
          break;
        }
        default: {                              // 未知格式，直接输出
          PUT('%');
          PUT(*fmt);
          fmt++;
          break;
        }
      }
    }
    else {
      PUT(*fmt++);
    }
  }
  #undef PUT
  if (n > 0) *p = '\0';
  return total;                        // 返回"本来会写多少"(标准语义)
}

//将可变参数按照 fmt 格式化输出到 out 中，返回本应写入的字符数（不含 \0）
//此外，snprintf() 函数提供了一个参数 size，如果格式化后的字符串长度超过了 size-1
//则 snprintf() 只会写入 size-1 个字符，并在字符串的末尾添加一个空字符（\0）以表示字符串的结束
//与vsnprintf不同的是，snprintf使用...而不是va_list
int snprintf(char *out, size_t n, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int ret = vsnprintf(out, n, fmt, ap);
  va_end(ap);
  return ret;
}


#endif
