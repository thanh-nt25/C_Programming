#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Binary_search_tree.h"


int main(void){
    node_t *root;
    InitTree(root);
    createNode(3);
    createNode(4);
    createNode(8);
    createNode(20);
    createNode(5);
    createNode(1);
    createNode(15);
    createNode(2);

    preOrder(root);

    return 0;
}