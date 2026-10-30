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

#include <isa.h>
#include <memory/vaddr.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>

#define BUF_SIZE 35   //用于token.str的长度，存储2位0b+32位二进制数值+1位'\0'，正好满足内存地址显示

enum {
  TK_SPACE= 256,  TK_HEX, TK_DEC,  TK_REG, TK_UNSIGNED, 
  TK_EQ,  TK_NEQ, TK_AND, TK_OR, TK_LE,  TK_GE, TK_LT, TK_GT,
  TK_DEREF, TK_NEG,


  /* TODO: Add more token types */

};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */

  {"0[xX][0-9a-fA-F]+", TK_HEX},      // 16进制数
  {"[0-9]+", TK_DEC},      // 10进制数
  {"\\$", '$'},          // 取寄存器值符号
  {"zero|ra|sp|gp|tp|t[0-6]|s[0-9]|a[0-7]|s10|s11|pc", TK_REG},  // 寄存器名
  {"\\+", '+'},         // 加号
  {"\\-", '-'},         // 减号或者负号
  {"\\*", '*'},         // 乘号或指针解引用
  {"\\/", '/'},         // 除号
  {"\\(", '('},         // 左括号
  {"\\)", ')'},         // 右括号
  {" +", TK_SPACE},    // 空格
  {"u", TK_UNSIGNED},   // 无符号后缀
  {"==", TK_EQ},        // 等于
  {"!=", TK_NEQ},       // 不等于
  {"&&", TK_AND},       // 逻辑与
  {"\\|\\|", TK_OR},    // 逻辑或
  {"<=", TK_LE},        // 小于等于
  {">=", TK_GE},        // 大于等于
  {"<", TK_LT},         // 小于
  {">", TK_GT},         // 大于
};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;
  char str[BUF_SIZE]; 
} Token;

static Token tokens[65536] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

//将表达式字符串放入tokens数组，返回true表示成功，false表示失败
static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /*将识别出的token写入结构体tokens中，同时将nr_tokens加1*/
        switch (rules[i].token_type) {
          case TK_HEX:
            Assert(substr_len < BUF_SIZE, "hex_token too long: %.*s",
                            substr_len, substr_start);  //避免token过长导致溢出
            tokens[nr_token].type = TK_HEX;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            tokens[nr_token].str[substr_len] = '\0';
            nr_token++;
            break;
          case TK_DEC:
            Assert(substr_len < BUF_SIZE, "dec_token too long: %.*s", 
                            substr_len, substr_start);  //避免token过长导致溢出
            tokens[nr_token].type = TK_DEC;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            tokens[nr_token].str[substr_len] = '\0';
            nr_token++;
            break;
          case '$':
            tokens[nr_token].type = rules[i].token_type;
            nr_token++;
            break;
          case TK_REG:
            Assert(substr_len < BUF_SIZE, "reg_token too long: %.*s", 
                            substr_len, substr_start);  //避免token过长导致溢出
            tokens[nr_token].type = TK_REG;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            tokens[nr_token].str[substr_len] = '\0';
            nr_token++;
            break;
          case '+':case '-':case '*':case '/':case '(':case ')':
            tokens[nr_token].type = rules[i].token_type;
            nr_token++;
            break;
          case TK_SPACE:case TK_UNSIGNED:
            break;
          case TK_EQ:case TK_NEQ:case TK_AND:case TK_OR:
          case TK_LE:case TK_GE:case TK_LT:case TK_GT:
            tokens[nr_token].type = rules[i].token_type;
            nr_token++;
            break;
          
          default: panic("请在make_token函数中添加新的token类型的处理逻辑");
        }

        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  return true;
}

/*判断 token 类型是否为运算符或左括号，用于判断下一个运算符"*"和"-"的情况
  谢天谢地，这些运算符判断时前一个运算符无论判没判断结果都一样
  （例如*前是-无论是减号还是负号都要判断*为解指针负号）*/
static bool is_op(int type) {
  switch (type) {
    case '+': case '-': case '*': case '/':
    case '(': case TK_EQ: case TK_NEQ:
    case TK_AND: case TK_OR:
    case TK_LE: case TK_GE: case TK_LT: case TK_GT:
    case TK_DEREF: case TK_NEG:
      return true;
    default:
      return false;
  }
}

//查看表达式中是否有解指针*并将其标记为TK_DEREF类型
static void check_deref(void) {
  for (int i = 0; i < nr_token; i++) {
    if (tokens[i].type == '*' && (i == 0 || is_op(tokens[i - 1].type))) {
      tokens[i].type = TK_DEREF;  //将*标记为解指针
    }
  }
}

//查看表达式中是否有负号'-'并将其标记为TK_NEG类型
static void check_negative_symbol(void) {
  for (int i = 0; i < nr_token; i++) {
    if (tokens[i].type == '-' && (i == 0 || is_op(tokens[i - 1].type))) {
      tokens[i].type = TK_NEG;  //将-标记为负号
    }
  }
}

//检查表达式中是否有括号不匹配导致的错误
static void check_brackets(void) {
  int depth = 0;
  for (int i = 0; i < nr_token; i++) {
    if (tokens[i].type == '(') {
      depth++;
    } else if (tokens[i].type == ')') {
      depth--;
    }
    if (depth < 0) {
      panic("括号不匹配：位置 %d 处多余的 ')'", i);
    }
  }
  if (depth > 0) {
    panic("括号不匹配：存在 %d 个未闭合的 '('", depth);
  }
}

//检查是否是一组对应的括号表达式
static bool check_parentheses(int p, int q){
  if (tokens[p].type != '(' || tokens[q].type != ')') {
    return false;
  }

  int count = 0;
  for (int i = p; i < q ; i++){
    if (tokens[i].type == '(') {
      count++;
    } else if (tokens[i].type == ')') {
      count--;
    }
    if (count == 0) {
      return false;
    }
  }

  return true;
}

//找到主运算符，返回其在tokens数组中的位置
static int main_operator(int p, int q) {
  int op = -1;
  int min_precedence = 100;   //运算符优先级，初始值为一个较大的数，确保任何运算符的优先级都小于它
  int parentheses_depth = 0;  //括号深度，初始值为0，表示当前不在任何括号内

  for (int i = p; i <= q; i++) {
    if (tokens[i].type == '(') {
      parentheses_depth++;
    } else if (tokens[i].type == ')') {
      parentheses_depth--;
    } else if (parentheses_depth == 0) { // 主运算符一定要在括号外部
      int precedence;
      switch (tokens[i].type) {
        case TK_OR:
          precedence = 1;
          break;
        case TK_AND:
          precedence = 2;
          break;     
        case TK_EQ:case TK_NEQ:
          precedence = 3;
          break;   
        case TK_LE:case TK_GE:case TK_LT:case TK_GT:
          precedence = 4;
          break;  
        case '+':case '-':
          precedence = 5;
          break;
        case '*':case '/':
          precedence = 6;
          break;
        case TK_DEREF:case TK_NEG:
          precedence = 7;
          break;
        case '$':
          precedence = 8;
          break;
        default:
          continue;  //跳过非运算符token 
      }

      if (precedence <= min_precedence) {
        min_precedence = precedence;
        op = i;
      }
    }
  }

  return op;
}

//计算对应表达式值
static word_t eval(int p, int q) {
  if (p > q) {
    panic("表达式错误");
  }
  else if (p == q) {
    switch (tokens[p].type) {
      case TK_HEX:
        return strtoul(tokens[p].str, NULL, 16);
      case TK_DEC:
        return atoi(tokens[p].str);
      default: panic("表达式错误");
    }
  }
  else if (check_parentheses(p, q) == true) {
    return eval(p + 1, q - 1);
  }
  else {
    int op = main_operator(p, q) ; //找到主运算符位置
    
    switch (tokens[op].type) {
      case TK_DEREF: {                         //处理解指针
        word_t addr = eval(op + 1, q);
        return vaddr_read(addr, 4);            //假设读取4字节数据
      }
      case TK_NEG: {                           //处理负号
        word_t val = eval(op + 1, q);
        return -val;
      }
      case '$': {                              //处理寄存器取值
        bool success;
        word_t reg_val = isa_reg_str2val(tokens[op+1].str, 
                                              &success);  //查看下一个token对应的寄存器名
        if (!success) {
          panic("无效的寄存器名: %s", tokens[op+1].str);
        }
        return reg_val;
      }
    }

    word_t val1 = eval(p, op - 1);
    word_t val2 = eval(op + 1, q);

    switch (tokens[op].type) {
      case '+': return val1 + val2;
      case '-': return val1 - val2;
      case '*': return val1 * val2;
      case '/': 
        Assert(val2 != 0, "除数不能为零");
        return val1 / val2;
      case TK_EQ: return val1 == val2;
      case TK_NEQ: return val1 != val2;
      case TK_AND: return val1 && val2;   
      case TK_OR: return val1 || val2;
      case TK_LE: return val1 <= val2;
      case TK_GE: return val1 >= val2;
      case TK_LT: return val1 < val2;
      case TK_GT: return val1 > val2;
      default: panic("请在eval函数中添加运算符的运算逻辑");
    }
  }
}

//表达式词法分析，语法分析，计算表达式值
word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }

  check_deref();
  check_negative_symbol();

  check_brackets();

  *success = true;
  return eval(0, nr_token - 1);
}
