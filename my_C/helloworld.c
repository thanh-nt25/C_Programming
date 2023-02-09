#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preOrderTraversal(struct node* node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->data);
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

void inOrderTraversal(struct node* node) {
    if (node == NULL) {
        return;
    }
    inOrderTraversal(node->left);
    printf("%d ", node->data);
    inOrderTraversal(node->right);
}

void postOrderTraversal(struct node* node) {
    if (node == NULL) {
        return;
    }
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    printf("%d ", node->data);
}

int main() {
    struct node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    printf("Preorder traversal of binary tree is \n");
    preOrderTraversal(root);
    printf("\nInorder traversal of binary tree is \n");
    inOrderTraversal(root);
    printf("\nPostorder traversal of binary tree is \n");
    postOrderTraversal(root);
    printf("\n");
    return 0;
}
