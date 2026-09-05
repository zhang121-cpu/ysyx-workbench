#include "klibtest.h"
#include <limits.h>

static void test_sprintf() {
    int data[] = {0, INT_MAX / 17, INT_MAX, INT_MIN, INT_MIN + 1,
                UINT_MAX / 17, INT_MAX / 17, UINT_MAX};
    static const char *expected[] = {
        "0", "126322567", "2147483647", "-2147483648",
        "-2147483647", "252645135", "126322567", "-1"
    };
    char buf[32];
    int i;
    for (i = 0; i < sizeof(data) / sizeof(data[0]); i ++) {
        sprintf(buf, "%d", data[i]);           // 实际输出
        assert(strcmp(buf, expected[i]) == 0); // 与预期输出对比
    }
}

void test_stdio(){
    test_sprintf();
    printf("前提是string中的strcmp pass!\n"); 
    printf("test_sprintf pass!\n");  //printf在klib中没有实现，无法使用,待实现后可以删掉注释
}
