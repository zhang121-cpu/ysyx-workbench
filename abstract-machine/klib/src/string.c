#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

//返回字符串中字符的个数（不含末尾的 \0）
size_t strlen(const char *s) {
  size_t i = 0;
  while(s[i] !=  '\0'){
    i++;
  }
  return i;
}

//把 src 指向的字符串（连同末尾的 \0）复制到 dst，返回 dst
char *strcpy(char *dst, const char *src) {
  char *d = dst;                        //工作指针，负责移动
  while (*src != '\0') {
    *d = *src;
    d++;
    src++;
  }
  *d = *src;                            //复制末尾的 \0
  return dst;                           //返回形参（起始地址）
}

//最多从 src 复制 n 个字符到 dst，返回dst。如果 src 长度不足 n，则用 \0 填充剩余部分
char *strncpy(char *dst, const char *src, size_t n) {
  size_t i = 0;
  char *d = dst;                        //工作指针，负责移动
  while (i < n && *src != '\0') {
    *d = *src;
    d++;
    src++;
    i++;
  }                           
  while (i < n) {                        //如果src不足n个字符，则在dst后面补'/0'
    *d = '\0';
    d++;
    i++;
  }
  return dst;                           //返回形参（起始地址）
}

//把 src 追加到 dst 末尾（覆盖掉 dst 末尾的 \0），返回 dst
char *strcat(char *dst, const char *src) {
  char *d = dst + strlen(dst);            //工作指针，移动到字符串末尾
  strcpy(d, src);                          
  return dst;                              //返回形参（起始地址）
}

//按字典序比较 s1 和 s2，返回值 < 0 表示 s1 < s2，返回值 = 0 表示 s1 = s2，返回值 > 0 表示 s1 > s2
int strcmp(const char *s1, const char *s2) {
  while (*s1 != '\0' &&  *s2 != '\0') {
    if (*s1 != *s2) {
      break;
    }
    s1++;
    s2++;
  }
  return (unsigned char)*s1 - (unsigned char)*s2;    //返回两个字符的差值，(unsigned char)确保比较结果为无符号整数
}

//同上，但最多只比较前 n 个字符
int strncmp(const char *s1, const char *s2, size_t n) {
  size_t i = 0;
  while (i < n && *s1 != '\0' && *s2 != '\0') {
    if (*s1 != *s2) {
      break;
    }  
    s1++;
    s2++;
    i++;
  }
  if (i == n) {        //如果前n个字符都相等，返回0，不再进行比较（其实可以使用s1--,s2--的方案，但到时又面临n=0的情况，这在写法将其包含了）
    return 0;
  }
  return (unsigned char)*s1 - (unsigned char)*s2;    //返回两个字符的差值，(unsigned char)确保比较结果为无符号整数
}

//把 s 的前 n 个字节都设为 c，返回 s
void *memset(void *s, int c, size_t n) {
  unsigned char *p = s;  
  for (size_t i = 0; i < n; i++) {
    p[i] = (unsigned char)c;               //将每个字节设置为指定的值c，c被强制转换为unsigned char类型是手册定义的
  }
  return s;
}

//功能同 memcpy，但允许源和目的区域重叠。重叠时从后往前拷即可
void *memmove(void *dst, const void *src, size_t n) {
  size_t i = 0;
  char *d = (char *)dst;                  //工作指针，负责移动
  const char *s = (const char *)src;
  if (s < d) {                  //如果源地址小于目的地址，说明有重叠，从后往前拷贝
    d += n - 1;
    s += n - 1;
    while (i < n) {
      *d = *s;
      d--;
      s--;
      i++;
    }
  } else {                        //否则从前往后拷贝
    while (i < n) {
      *d = *s;
      d++;
      s++;
      i++;
    }
  }
  return dst;                             //返回形参（起始地址）
}

//把 in 的前 n 个字节复制到 out，返回 out。要求源和目的不重叠（如重叠需用 memmove）
void *memcpy(void *out, const void *in, size_t n) {
  size_t i = 0;
  char *d = (char *)out;                  //工作指针，负责移动
  const char *s = (const char *)in;
  while (i < n) {
    *d = *s;
    d++;
    s++;
    i++;
  }
  return out;                             //返回形参（起始地址）
}

//存储区 s1 和存储区 s2 的前 n 个字节进行比
int memcmp(const void *s1, const void *s2, size_t n) {
  size_t i = 0;
  while (i < n) {
    if (*(unsigned char *)s1 != *(unsigned char *)s2) {
      break;
    }
    s1++;
    s2++;
    i++;
  }
  if (i == n) {        //如果前n个字符都相等，返回0，不再进行比较（其实可以使用s1--,s2--的方案，但到时又面临n=0的情况，这在写法将其包含了）
    return 0;
  }
  return *(unsigned char *)s1 - *(unsigned char *)s2;    //返回两个字节的差值，(unsigned char)确保比较结果为无符号整数
}

#endif
