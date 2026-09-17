#include <am.h>
#include <klib.h>
#include <klib-macros.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)
static unsigned long int next = 1;

#define TEM_SIZE 32

int rand(void) {
  // RAND_MAX assumed to be 32767
  next = next * 1103515245 + 12345;
  return (unsigned int)(next/65536) % 32768;
}

void srand(unsigned int seed) {
  next = seed;
}

int abs(int x) {
  return (x < 0 ? -x : x);
}

int atoi(const char* nptr) {
  int x = 0;
  int neg = 0;

  //跳过前面的空格
  while (*nptr == ' ') { nptr ++; }

  // 处理正负号
  if (*nptr == '-') {
    neg = 1;
    nptr++;
  } else if (*nptr == '+') {
    nptr++;
  }

  //解析数组
  while (*nptr >= '0' && *nptr <= '9') {
    x = x * 10 + *nptr - '0';
    nptr ++;
  }
  return neg ? -x : x;             // 根据符号返回
}

char *itoa(int value, char *str, int base) {
  char *p = str;
  char tmp[TEM_SIZE];
  int i = 0;
  unsigned int v = (unsigned int)value;
  int neg = (value < 0 && base == 10); // 仅在十进制下处理负数

  if (neg == 1) {
    *p++ = '-';
    v = (unsigned int)(-(value + 1)) + 1u;   // 负数取绝对值, INT_MIN 也不溢出
  }
  do {                                                   //保证至少执行一次循环，tmp中有值
    tmp[i++] = "0123456789abcdef"[v % base];  //查表法放入余数
    v /= base;
  } while (v > 0);            

  while (i > 0) {
    *p++ = tmp[--i];               //将 tmp 中的字符倒序复制到 str 中
  }
  *p = '\0';
  return str;
}

// On native, malloc() will be called during initializaion of C runtime.
// Therefore do not call panic() here, else it will yield a dead recursion:
//   panic() -> putchar() -> (glibc) -> malloc() -> panic()
// 在原生环境中，C 运行时初始化期间会调用 malloc()。
// 因此，请勿在此处调用 panic()，否则将导致死循环：
//   panic() -> putchar() -> (glibc) -> malloc() -> panic()
void *malloc(size_t size) {
  static uint64_t _backup_heap[(1 << 20) / 8];  // 1MB 静态兜底堆
  static void *hbrk = NULL;
  static void *start  = NULL;
  static void *end  = NULL;

  if (hbrk == NULL) {
    // 首次调用：优先用 AM 的 heap，为空则用静态数组
    hbrk = (heap.start != heap.end) ? heap.start : (void *)_backup_heap;
    start = (heap.start != heap.end) ? heap.start : (void *)_backup_heap;
    end  = (heap.start != heap.end) ? heap.end   : (void *)_backup_heap + sizeof(_backup_heap);
    hbrk = (void *)ROUNDUP(hbrk, 8);     //把hbrk 向上取整到 8 的整数倍
  }

  size = (size_t)ROUNDUP(size, 8);     //把size 向上取整到 8 的整数倍
  void *addr = hbrk;      //hbrk模拟堆顶，addr保存当前分配位置
  hbrk += size;

  // 越界检查：根据当前使用的是 heap 还是静态数组判断上界
  assert((uintptr_t)start <= (uintptr_t)hbrk && (uintptr_t)hbrk < (uintptr_t)end);
  for (uint64_t *p = (uint64_t *)addr; p != (uint64_t *)hbrk; p ++) {
    *p = 0;
  }
  return addr;
}

void free(void *ptr) {
}

#endif
