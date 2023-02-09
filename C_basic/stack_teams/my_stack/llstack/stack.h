#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include "llist.h"

typedef root_t stack_t;

stack_t stackInit();

int isEmpty(stack_t stack);
int isFull(stack_t stack);

stack_t push(stack_t stack, const data_t data);
stack_t pop(stack_t stack);
stack_t popData(stack_t stack, data_t *pData);


#endif