#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include "data_t.h"

#define MAX 50

enum {EXIT_SUCCESS = 0, EXIT_STACK_OVERFLOW, EXIT_STACK_UNDERFLOW};

typedef data_t elem_t;

typedef struct stack_s{
    elem_t storage[MAX];
    int top;
}   stack_t;

void initialize(stack_t *pStack);
int isEmpty(stack_s stack);
int isFull


#endif