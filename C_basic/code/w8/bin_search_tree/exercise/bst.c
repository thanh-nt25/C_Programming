// BST: Bin Search Tree
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

tree_t search(key_t x, tree_t root) {
  // Enter your code here
}

void insertNode(data_t x, tree_t *pRoot) {
  // Enter your code here
}

// Find the left-most node of right sub tree
key_t deleteMin(tree_t *root) {
  // Enter your code here
}

// Delete a node from a BST
void deleteNode(key_t x, tree_t *root) {
  // Enter your code here
}

void prettyPrint(tree_t tree) {
  static char prefix[200] = "    ";
  char *prefixend = prefix + strlen(prefix);
  if (tree != NULL) {
    printf("'%04s'", tree->data.key);       // <===
    if (tree->left != NULL)
      if (tree->right == NULL) {
        printf("\304");
        strcat(prefix, "     ");
      } else {
        printf("\302");
        strcat(prefix, "\263    ");
      }
    prettyPrint(tree->left);
    *prefixend = '\0';
    if (tree->right != NULL)
      if (tree->left != NULL) {
        printf("\n%s", prefix);
        printf("\300");
      } else
        printf("\304");
    strcat(prefix, "     ");
    prettyPrint(tree->right);
  }
}

void freeTree(tree_t tree) {
  if (tree != NULL) {
    freeTree(tree->left);
    freeTree(tree->right);
    free((void *)tree);
  }
}