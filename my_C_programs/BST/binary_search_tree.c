#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef int key_t;

typedef struct node_s {
    key_t key;
    struct node_s *left;
    struct node_s *right;
}   node_t;

// dinh nghia lai node_t la mot con tro
typedef node_t *tree_t;

void freeTree(tree_t tree){
    if (tree != NULL){
        freeTree(tree->left);
        freeTree(tree->right);
        free((void*)tree);
    }
}

void insertNode(key_t x, tree_t *pRoot){
    if(*pRoot == NULL){
        *pRoot = (node_t*)malloc(sizeof(node_t));
        (*pRoot)->left = NULL;
        (*pRoot)->right = NULL;
        (*pRoot)->key = x;
    }
    else if (x<)
}
