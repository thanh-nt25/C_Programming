#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "BST.h"

// typedef node_type *root;

node_type *createNode(elmType data){
    node_type *newNode = (node_type *)malloc(sizeof(node_type));
    if (newNode == NULL) return NULL;
    newNode -> key = data;
    newNode -> right = NULL;
    newNode -> left = NULL;
    return newNode;
}

// void *insertNode(node_type* root, elmType newData){
//     if (root == NULL) {
//         return createNode(newData);
//     }
//     if (root -> key < newData){
//         root -> right = insertNode(root -> right, newData);
//     }
//     else if(root -> key > newData){
//         root->left = insertNode(root -> left, newData);
//     }
//     return root;
// }

void *insertNode(node_type *root, elmType newData){
    node_type *newnode = createNode(newData);
    if (newnode == NULL) return NULL;
    if (root == NULL) return newnode;
    if (root->key > newData){
        root->left = insertNode(root->left, newData);
    }
    if (root->key < newData){
        root->right = insertNode(root->right, newData);
    }
    return root;
}



