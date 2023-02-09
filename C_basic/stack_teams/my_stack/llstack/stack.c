#include <stdlib.h>
#include "stack.h"

stack_t stackInit(){
    return llInit();
}

int isEmpty(stack_t stack){
    return stack == NULL;
    // 1 = empty, 0 = con cho, != 0 la empty
}

int isFull(stack_t stack){
    return 0;
}

stack_t push(stack_t stack, data_t data){
    return llInsertHead(stack, data);
}