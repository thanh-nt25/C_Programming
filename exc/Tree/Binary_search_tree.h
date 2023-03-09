#ifndef __BINARY_SEARCH_TREE_C__
#define __BINARY_SEARCH_TREE_C__

#include <stdio.h>
#include <stdlib.h>
#include "data_h.h"

typedef struct node_s{
    data_t data;
    struct node_s *leftChild;
    struct node_s *rightChild;
}   node_t;

node_t *createNode(data_t data);

void InitTree(node_t *root);
void InsertNode(node_t *root, data_t data);

void inOrder(node_t *root);
void postOrder(node_t *root);
void preOrder(node_t *root);

void FreeTree(node_t *root);

#endif