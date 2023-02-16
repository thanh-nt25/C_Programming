#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int elmType;

typedef struct nodeType{
    elmType key;
    struct nodeType *left, *right;
}   node_type;

typedef node_type *root;

node_type *createNode(elmType data){
    node_type *newNode = (node_type *)malloc(sizeof(node_type));
    if (newNode == NULL) return NULL;
    newNode -> key = data;
    newNode -> right = NULL;
    newNode -> left = NULL;
    return newNode;
}

void *insertNode(root root, elmType newData){
    if (root == NULL) {
        return createNode(newData);
    }
    if (root -> key < newData){
        insertNode(root -> right, newData);
    }
    else if(root -> key > newData){
        insertNode(root -> left, newData);
    }
}

void inOrder(node_type *root){
    if (root != NULL){
    inOrder(root -> left);
    printf("%d \t", root -> key);
    inOrder(root -> right);
    }
}

int main(void){
    // node_type *root = NULL;
    // init_tree(root);
    root tree = NULL;

    insertNode(tree, 50);
    insertNode(tree, 30);
    insertNode(tree, 20);
    insertNode(tree, 40);
    insertNode(tree, 70);
    insertNode(tree, 60);
    insertNode(tree, 80);
    inOrder(tree);
    printf("\n");
    return 0;
}   