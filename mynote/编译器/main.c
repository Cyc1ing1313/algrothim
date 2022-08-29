#include <fcntl.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
// #define int long long
enum {
  LEA,
  IMM,
  JMP,
  CALL,
  JZ,
  JNZ,
  ENT,
  ADJ,
  LEV,
  LI,
  LC,
  SI,
  SC,
  PUSH,
  OR,
  XOR,
  AND,
  EQ,
  NE,
  LT,
  GT,
  LE,
  GE,
  SHL,
  SHR,
  ADD,
  SUB,
  MUL,
  DIV,
  MOD,
  OPEN,
  READ,
  CLOS,
  PRTF,
  MALC,
  MSET,
  MCMP,
  EXIT
};

int token;
char *src, *old_src;
int pool_size;
int line;
int *text, *old_text, *stack;
char *data;
int *pc, *bp, *sp, ax, cycle;

void next() {
  token = *src++;
  return;
}

void program() { //语法分析
  next();
  while (token > 0) {
    printf("token is %c\n", token);
    next(); //词法分析
  }
}

//解析表达式
void expression(int level) {}

//运行
int eval() {
  int op, *tmp;
  while (1) {
    op = *pc++;
    if (op == IMM) {
      ax = *pc++;
    } else if (op == LC) {
      ax = *(char *)ax;
    } else if (op == LI) {
      ax = *(int *)ax;
    } else if (op == SC) {
      *(char *)*sp++ = ax;
    } else if (op == SI) {
      *(int *)*sp++ = ax;
    } else if (op == PUSH) {
      *--sp = ax;
    } else if (op == JMP) {
      pc = (int *)*pc;
    } else if (op == JZ) {
      pc = ax ? pc + 1 : (int *)*pc;
    } else if (op == JNZ) {
      pc = ax ? (int *)pc : pc + 1;
    } else if (op == ENT) {
      *--sp = (int)bp;
      bp = sp;
      sp = sp - *pc++;
    } else if (op == ADJ) {
      sp = sp + *pc++;
    } else if (op == LEV) {
      sp = bp;
      bp = (int *)*sp--;
      pc = (int *)*sp++;
    } else if (op == LEA) {
      ax = (int)(bp + *pc++);
    } else if (op == OR)
      ax = *sp++ | ax;
    else if (op == XOR)
      ax = *sp++ ^ ax;
    else if (op == AND)
      ax = *sp++ & ax;
    else if (op == EQ)
      ax = *sp++ == ax;
    else if (op == NE)
      ax = *sp++ != ax;
    else if (op == LT)
      ax = *sp++ < ax;
    else if (op == LE)
      ax = *sp++ <= ax;
    else if (op == GT)
      ax = *sp++ > ax;
    else if (op == GE)
      ax = *sp++ >= ax;
    else if (op == SHL)
      ax = *sp++ << ax;
    else if (op == SHR)
      ax = *sp++ >> ax;
    else if (op == ADD)
      ax = *sp++ + ax;
    else if (op == SUB)
      ax = *sp++ - ax;
    else if (op == MUL)
      ax = *sp++ * ax;
    else if (op == DIV)
      ax = *sp++ / ax;
    else if (op == MOD)
      ax = *sp++ % ax;
    else if (op == EXIT) {
      printf("exit(%d)", *sp);
      return *sp;
    } else if (op == OPEN) {
      ax = open((char *)sp[1], sp[0]);
    } else if (op == CLOS) {
      ax = close(*sp);
    } else if (op == READ) {
      ax = read(sp[2], (char *)sp[1], *sp);
    } else if (op == PRTF) {
      tmp = sp + pc[1];
      ax = printf((char *)tmp[-1], tmp[-2], tmp[-3], tmp[-4], tmp[-5], tmp[-6]);
    } else if (op == MALC) {
      ax = (int)malloc(*sp);
    } else if (op == MSET) {
      ax = (int)memset((char *)sp[2], sp[1], *sp);
    } else if (op == MCMP) {
      ax = memcmp((char *)sp[2], (char *)sp[1], *sp);
    } else {
      printf("unknown instruction:%d\n", op);
      return -1;
    }
  }
}

int init_mem(int size) {
  if (!(text = old_text = malloc(size))) {
    return -1;
  }
  if (!(data = malloc(size))) {
    return -1;
  }
  if (!(stack = malloc(size))) {
    return -1;
  }
  memset(text, 0, size);
  memset(data, 0, size);
  memset(stack, 0, size);
  return 0;
}

void init_register(int size) {
  bp = sp = (int *)((int)stack + size);
  ax = 0;
}

int main(int argc, char **argv) {
  int i, fd, ret;
  argc--;
  argv++;

  pool_size = 256 * 1034;
  line = 1;

  if ((fd = open(*argv, 0)) < 0) {
    return -1;
  }
  if (!(src = old_src = malloc(pool_size))) {
    return -1;
  }
  if ((i = read(fd, src, pool_size - 1)) <= 0) {
    return -1;
  }
  src[i] = 0;
  close(fd);

  if ((ret = init_mem(pool_size) == -1)) {
    return -1;
  }
  init_register(pool_size);
  i = 0;
  text[i++] = IMM;
  text[i++] = 10;
  text[i++] = PUSH;
  text[i++] = IMM;
  text[i++] = 20;
  text[i++] = ADD;
  text[i++] = PUSH;
  text[i++] = EXIT;
  pc = text;
  program();
  return eval();
}