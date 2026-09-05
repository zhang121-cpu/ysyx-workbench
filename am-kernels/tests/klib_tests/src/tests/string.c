#include "klibtest.h"

#define N 32

uint8_t data[N];
uint8_t src[N]; 

static void reset() {
    int i;
    for (i = 0; i < N; i ++) {
        data[i] = i + 1;
        src[i] = N - i;
    }
}

// 检查[l,r)区间中的值是否依次为val, val + 1, val + 2...
static void check_seq(int l, int r, int val) {
    int i;
    for (i = l; i < r; i ++) {
    assert(data[i] == val + i - l);
    }
}

// 检查[l,r)区间中的值是否均为val
static void check_eq(int l, int r, int val) {
    int i;
    for (i = l; i < r; i ++) {
        assert(data[i] == val);
    }
}

//检查 data[l, r) 是否与 src 一致
static void check_eq_mem(int l, int r, uint8_t *src) {
    int i;
    for (i = l; i < r; i ++) {
        assert(data[i] == src[i - l]);
    }
}

static void test_strlen() {
    int l, r;
    for (l = 0; l < N; l ++) {
        for (r = l + 1; r <N; r ++) {
            reset();
            data[r] = '\0';                  
            assert(strlen((char *)(data + l)) == r - l);
        }
    }
}

static void test_strcpy() {
    int l, r;
    for (l = 0; l < N; l ++) {
        for (r = l + 1; r < N; r ++) {        
            reset();                            
            src[r - l] = '\0';                  
            strcpy((char *)(data + l), (char *)src);
            check_seq(0, l, 1);                 
            check_eq_mem(l, r, src);            
            assert(data[r] == '\0');            
            check_seq(r + 1, N, r + 2);         
        }
    }
}

static void test_strncpy() {
    int l, r, n;
    for (l = 0; l < N; l ++) {
        for (r = l + 1; r < N; r ++) {          
            for (n = 0; n <= N - l; n ++) {     
                reset();
                src[r - l] = '\0';           

                strncpy((char *)(data + l), (char *)src, n);

                if (n <= r - l) {
                    // 源足够: 只拷 n 个字符, 不写 '\0'
                    check_seq(0, l, 1);
                    check_eq_mem(l, l + n, src);
                    check_seq(l + n, N, l + n + 1);  
                } else {
                    // 源不足: 拷 r-l 个字符, 剩余补 '\0' 到 n
                    check_seq(0, l, 1);
                    check_eq_mem(l, r, src);
                    check_eq(r, l + n, 0);          
                    check_seq(l + n, N, l + n + 1);
                }
            }
        }
    }
}

static void test_strcat() {
    int l, r, i;
    for (l = 0; l < N; l ++) {
        for (r = l + 1; r < N; r ++) {      
            for (i = 0; i < l; i ++) {  
                reset();
                data[l] = '\0';             
                src[r - l] = '\0';             

                strcat((char *)(data + i), (char *)src);

                check_seq(0, l, 1);                                    
                check_eq_mem(l, r, src);           
                assert(data[ r] == '\0');           
                check_seq(r +1, N, r + 2);   
            }           
        }
    }
}

static void test_strcmp() {
    int l, r;
    for (l = 0; l < N; l ++) {
        for (r = l + 1; r < N; r ++) {        // 串长 = r - l
            int i;

            // 情况1: 两串内容相同、长度相同 → 0
            reset();
            for (i = 0; i < r - l; i ++) data[l + i] = src[i];   // 造出相同内容
            data[r] = '\0';                    // s1 = data+l, 长度 r-l
            src[r - l] = '\0';                 // s2 = src, 长度 r-l
            assert(strcmp((char *)(data + l), (char *)src) == 0);

            // 情况2: data 是 src 的前缀(短一个字符) → < 0
            reset();
            for (i = 0; i < r - 1 - l; i ++) data[l + i] = src[i];
            data[r - 1] = '\0';                // s1 长度 r-1-l
            src[r - l] = '\0';                 // s2 长度 r-l
            assert(strcmp((char *)(data + l), (char *)src) < 0);
            assert(strcmp((char *)src, (char *)(data + l)) > 0);   // 对称性

            // 情况3: 只有最后一个字符不同 → 符号由它决定
            reset();
            for (i = 0; i < r - l - 1; i ++) data[l + i] = src[i];
            data[r - 1] = 'a';
            src[r - l - 1] = 'b';
            data[r] = '\0';
            src[r - l] = '\0';
            assert(strcmp((char *)(data + l), (char *)src) < 0);
            assert(strcmp((char *)src, (char *)(data + l)) > 0);
        }
    }
}

static void test_strncmp() {
    int l, r, n;
    for (l = 0; l < N; l ++) {
        for (r = l + 1; r < N; r ++) {        // 串长 = r - l
            for (n = 0; n < N; n ++) {        // 比较长度
                int i;

                // 情况1: 两串完全相等 → 任何 n 都是 0
                reset();
                for (i = 0; i < r - l; i ++) data[l + i] = src[i];
                data[r] = '\0';
                src[r - l] = '\0';
                assert(strncmp((char *)(data + l), (char *)src, n) == 0);

                // 情况2: data 是 src 的前缀(短一个字符)
                reset();
                for (i = 0; i < r - 1 - l; i ++) data[l + i] = src[i];
                data[r - 1] = '\0';
                src[r - l] = '\0';
                if (n < r - l) assert(strncmp((char *)(data + l), (char *)src, n) == 0);
                else            assert(strncmp((char *)(data + l), (char *)src, n) < 0);

                // 情况3: 只有最后一个字符不同
                reset();
                for (i = 0; i < r - l - 1; i ++) data[l + i] = src[i];
                data[r - 1] = 'a';
                src[r - l - 1] = 'b';
                data[r] = '\0';
                src[r - l] = '\0';
                if (n < r - l) assert(strncmp((char *)(data + l), (char *)src, n) == 0);
                else            assert(strncmp((char *)(data + l), (char *)src, n) < 0);
            }
        }
    }
}

static void test_memset() {
    int l, r;
    for (l = 0; l < N; l ++) {
        for (r = l + 1; r <= N; r ++) {
            reset();
            uint8_t val = (l + r) / 2;
            memset(data + l, val, r - l);
            check_seq(0, l, 1);
            check_eq(l, r, val);
            check_seq(r, N, r + 1);
        }
    }
}

static void test_memmove() {
    int k;
    for (k = 1; k < N; k ++) {
        // 重叠右移 k 字节
        reset();
        memmove(data + k, data, N - k);
        check_seq(0, k, 1);        
        check_seq(k, N, 1);        

        // 重叠左移 k 字节
        reset();
        memmove(data, data + k, N - k);
        check_seq(0, N - k, k + 1);      
        check_seq(N - k, N, N - k + 1);  
    }
}

static void test_memcpy() {
    int l, r;
    for (l = 0; l < N; l ++) {
        for (r = l + 1; r <= N; r ++) {
            reset();
            memcpy(data + l, src, r - l);
            check_seq(0, l, 1);
            check_eq_mem(l, r, src);
            check_seq(r, N, r + 1);
        }
    }
}

static void test_memcmp() {
    int l, r, n;
    for (l = 0; l < N; l ++) {
        for (r = l + 1; r < N; r ++) {        // 串长 = r - l
            for (n = 0; n < N; n ++) {        // 比较长度
                int i;

                // 情况1: 只有最后一个字符不同
                reset();
                for (i = 0; i < r - l - 1; i ++) data[l + i] = src[i];
                data[r - 1] = 'a';
                src[r - l - 1] = 'b';
                if (n < r - l) assert(memcmp(data + l, src, n) == 0);
                else            assert(memcmp(data + l, src, n) < 0);
            }
        }
    }
}


void test_string(){
    test_memset();
    printf("test_memset pass!\n");
    test_memcpy();
    printf("test_memcpy pass!\n");
    test_strcpy();
    printf("test_strcpy pass!\n");
    test_strncpy();
    printf("test_strncpy pass!\n");
    test_strcat();
    printf("test_strcat pass!\n");
    test_memmove();
    printf("test_memmove pass!\n");
    printf("All write-function tests pass!\n");  //printf在klib中没有实现，无法使用,待实现后可以删掉注释

    test_strlen();
    printf("test_strlen pass!\n");
    test_strcmp();
    printf("test_strcmp pass!\n");
    test_strncmp();
    printf("test_strncmp pass!\n");
    test_memcmp();
    printf("test_memcmp pass!\n");
    printf("All read-function tests pass!\n");  //printf在klib中没有实现，无法使用,待实现后可以删掉注释
}


