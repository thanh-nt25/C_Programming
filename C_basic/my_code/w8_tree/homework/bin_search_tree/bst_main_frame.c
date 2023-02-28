// Exercise
// - Create an binary search tree with 10 nodes. Each node contains an random integer. 
// - Ask user to input an number and search for it.
// - Print the content of the trees. 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"


int main() {
  tree_t tree = NULL;
  srand(time(NULL));

  // Create an binary search tree with 10 nodes.
  // Each node contains an random integer.
  // --- Your code here ---
 
  // Print the content of the trees. 
  prettyPrint(tree);  printf("\n");

  int n = 0;  // n: user's input
  do {
    // Ask user to input an number and search for it.
    printf("Enter key to search (-1 to quit):");

    tree_t p;
    // Search 
    // --- Your code here ---

    if (p != NULL)
      printf("Key %d found on the tree\n\n", n);
    else {
      insertNode(n, &tree);
      prettyPrint(tree);
    }
  } while (n != -1);

  freeTree(tree);

  return EXIT_SUCCESS;
}