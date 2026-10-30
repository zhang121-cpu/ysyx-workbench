/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include "sdb.h"

#define NR_WP 32

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;
  char expr[32];   //表达式字符串不能超过32位（包含最后的'\0'）
  word_t value;
} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;
}

static WP* new_wp() {
  if (free_ == NULL) {
    panic("无剩余的可用监视点");
  }

  WP *free_new = free_;
  free_ = free_-> next;     //从free_链表中中取出一个监视点并将其放入head中

  WP *head_new = head;
  if (head == NULL) {
    head = free_new;              //如果head链表为空，将新监视点放入head链表的最前端
    free_new -> next = NULL;
  } else {
    while (head_new -> next != NULL)                          
      head_new = head_new -> next;      //遍历head链表找到最后一个监视点，并将新监视点放在其后
    head_new -> next = free_new;
    free_new -> next = NULL;
  }
  return free_new;
}

static void free_wp(WP *wp) {
  if (head == NULL) {
    panic("所有监视点都已放入空闲链表");
  }

  if (head == wp) {
    head = head -> next;         //如果head对应监视点就是目标，将head指向下一个监视点
  } else {
    WP *head_new = head;
    while (head_new -> next != wp && head_new -> next != NULL)    
      head_new = head_new -> next;      //遍历head链表找到目标监视点的前一个监视点，并对其处理
    if (head_new -> next == wp) 
      head_new -> next = wp -> next;
    else
      panic("链表中没有该监视点");
    }
  
  if (free_ == NULL) {
  wp -> next = NULL;     //将被移除的监视点放入free_链表的最前端
  free_ = wp;
  } 

  if (free_ -> NO  > wp -> NO) {
    wp -> next = free_;       //将被移除的监视点放入free_链表的最前端
    free_ = wp;
  } else {
    WP *free_new = free_;          //将被移除的监视点放在按NO升序排列的free_链表中
    while ((free_new -> next -> NO) < (wp -> NO) && free_new -> next != NULL)
      free_new = free_new -> next;
    if ((free_new -> next -> NO) < (wp -> NO) ){
      wp -> next = free_new -> next;
      free_new -> next = wp;
    } else{
      wp -> next = NULL;
      free_new -> next = wp;
    }
  }

  return;
}

//显示所有监视点信息
void wp_display(){
  if (head == NULL) {
    printf("没有监视点\n");
    return;
  } else {
    WP *new = head;
    printf("监视点列表：\n");
    printf("编号\t表达式\t\t值\n");
    while  (new != NULL) {
      printf("%d\t%s\t\t0x%x(%u)\n", new -> NO, new -> expr, new -> value, new -> value);
      new = new -> next;
    }    
    return;
  }
}

//设置一个监控点
void wp_set (char *args, word_t value) {
  WP *new = new_wp();
  strncpy(new -> expr, args, sizeof(new -> expr) - 1);
  new -> expr[sizeof(new -> expr) - 1] = '\0';  // 确保以'\0'结尾
  new -> value = value;
  printf("监视点%d已设置\t表达式为%s\t值为0x%x(%u)\n", 
                    new -> NO, new -> expr, new -> value, new -> value);
  return;
}

//删除一个监控点
void wp_d(int NO) {
  WP *new = head;
  while (new != NULL) {
    if (new -> NO == NO) {
      free_wp(new);
      printf("监视点%d已删除\n", NO);
      return;
    }
    new = new -> next;
  }
  printf("没有编号为%d的监视点\n", NO);
  return;
}

//检测每个监视点的值是否发生变化
int wp_check(){
  int symbol = 0;
  if (head == NULL)
    return symbol;

  WP *new = head;
  while (new != NULL){
    bool success;
    word_t result = expr(new -> expr, &success);

    if (!success) {
      printf("表达式无法计算： %s\n", new -> expr);
      new = new -> next;
      continue;
    } 

    if (result != new -> value) {
      symbol = 1;
      printf("监视点%d: %s\n旧值 = 0x%x(%u)\n新值 = 0x%x(%u)\n", 
                      new -> NO, new -> expr, new -> value, new -> value, 
                      result, result);
      new -> value = result;  // 更新为新值
    }
    new = new -> next;
  }
  return symbol;
}


