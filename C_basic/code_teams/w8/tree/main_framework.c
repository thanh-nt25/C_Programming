#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

int treeHeight(treetype t) {
  // your code here
}
int treeNbrLeaf(treetype t) {
  // your code here
}
int treeInternalNode(treetype t) { 
  // your code here 
}
int treeNbrRightChildren(treetype t) {
  // your code here
}

int main() {
  treetype tr;
  makeNullTree(&tr);
  if (isEmptyTree(tr)) printf("Empty Tree\n");

  for (int i = 0; i < 10; i++) 
    Add_Left(&tr, 10+i);
  for (int i = 0; i < 5; i++) 
    Add_Right(&tr, 100 + i);

  // tr = createfrom2(1000, tr, tr);

  printf("Tree Height: %d\n", treeHeight(tr));
  printf("So la: %d\n", treeNbrLeaf(tr));
  printf("# internal node: %d\n", treeInternalNode(tr));
  printf("# right children: %d\n", treeNbrRightChildren(tr));
  return 0;
}