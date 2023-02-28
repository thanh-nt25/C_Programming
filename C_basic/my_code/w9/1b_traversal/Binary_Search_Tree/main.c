#include <stdio.h>
#include "bst_traversal.h"

int main(void){
    node_type *root = NULL;
    // init_tree(root);
    // root tree = NULL;
    root = insertNode(root, 6);
    insertNode(root, 5);
    insertNode(root, 4);
    insertNode(root, 3);
    insertNode(root, 2);
    insertNode(root, 1);
    insertNode(root, 7);
    insertNode(root, 8);
    insertNode(root, 9);
    insertNode(root, 0);


    printf("Inorder:\n");
    inOrder(root); printf("\n");
    printf("PostOrder:\n");
    postOrder(root); printf("\n");
    printf("PreOrder:\n");
    preOrder(root); printf("\n");
    return 0;
}   