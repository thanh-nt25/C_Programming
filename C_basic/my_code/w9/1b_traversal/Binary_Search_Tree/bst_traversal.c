#include <stdio.h>
#include "bst_traversal.h"


void inOrder(node_type *root){
    if (root != NULL){
    inOrder(root -> left);
    printf("%d \t", root -> key);
    inOrder(root -> right);
    }
}

void preOrder(node_type *root){
    if(root != NULL){
        printf("%d\t", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(node_type *root){
    if (root != NULL){
    postOrder(root->left);
    postOrder(root->right);
    printf("%d\t", root->key);
    }
}