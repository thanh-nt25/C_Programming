#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Binary_search_tree.h"

node_t *createNode(data_t data){
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    newNode -> data = data;
    newNode -> leftChild = NULL;
    newNode -> rightChild = NULL;
}

void InitTree(node_t *root){ root = NULL;}

void InsertNode(node_t *root, data_t data){
    node_t *newNode = createNode(data);
    if (root == NULL) root = newNode;
    if(lt(root->data, data)){
        InsertNode(root->leftChild, data);
    }
    if(gt(root->data, data)){
        InsertNode(root->rightChild, data);
    }
}

void inOrder(node_t *root){
    if(root == NULL) return;
    inOrder(root->leftChild);
    showdata(root->data);
    inOrder(root->rightChild);
}

void postOrder(node_t *root){
    if(root == NULL) return;
    postOrder(root->leftChild);
    postOrder(root->rightChild);
    showdata(root->data);
}

void preOrder(node_t *root){
    if(root == NULL) return;
    showdata(root->data);
    preOrder(root->leftChild);
    preOrder(root->rightChild);
}

void FreeTree(node_t *root){
    free(root->leftChild);
    free(root->leftChild);
    free(root);
}