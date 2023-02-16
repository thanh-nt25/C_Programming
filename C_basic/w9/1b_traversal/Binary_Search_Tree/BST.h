#ifndef __BST_H__
#define __BST_H__

#include <stdio.h>


typedef int elmType;

typedef struct nodeType{
    elmType key;
    struct nodeType *left, *right;
}   node_type;

node_type *createNode(elmType data);
void *insertNode(node_type *root, elmType newData);

#endif
