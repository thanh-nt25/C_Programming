#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// #include "tree.h"

/*===================== init ==================*/ 

typedef struct {
  char op;
  int number;
} elmType;
// whatever type of element

// typedef int elmType;

typedef struct nodeType {
  elmType element;
  struct nodeType *left, *right;
} node_type;

typedef struct nodeType *treetype;

/*================ functions =================*/

void makeNullTree(treetype *T) { (*T) = NULL; }
int isEmptyTree(treetype T) { return T == NULL; }

treetype LeftChild(treetype n) {
  if (n != NULL)
    return n->left;
  else
    return NULL;
}

treetype RightChild(treetype n) {
  if (n != NULL)
    return n->right;
  else
    return NULL;
}

node_type *create_node(elmType NewData) {
  node_type *N = (node_type *)malloc(sizeof(node_type));
  if (N != NULL) {
    N->left = NULL;
    N->right = NULL;
    N->element = NewData;
  }
  return N;
}

// kiem tra 1 nut co phai nut la ko
int IsLeaf(treetype n) {
  if (n != NULL)
    return (LeftChild(n) == NULL) && (RightChild(n) == NULL);
  else
    return -1;
}

// dem so nut
// su dung de qui
int nb_nodes(treetype T) {
  if (isEmptyTree(T))
    return 0;
  else
    // so nut trai + so nut phai
    return 1 + nb_nodes(LeftChild(T)) + nb_nodes(RightChild(T));
}

// tao mot cay con tu 2 cay con trai va phai
treetype createfrom2(elmType v, treetype l, treetype r) {
  node_type *N = (node_type *)malloc(sizeof(node_type));
  N->element = v;
  N->left = l;
  N->right = r;
  return N;
}

// left most position: truyen node cuoi cung ben trai
treetype Add_Left(treetype *Tree, elmType NewData) {
  node_type *NewNode = create_node(NewData);
  if (NewNode == NULL) return (NewNode);
  if (*Tree == NULL)
    *Tree = NewNode;
  else {
    node_type *Lnode = *Tree;
    while (Lnode->left != NULL) Lnode = Lnode->left;
    Lnode->left = NewNode;
  }
  return (NewNode);
}

// right most position: truyen node cuoi cung ben phai
treetype Add_Right(treetype *Tree, elmType NewData) { 
   node_type *NewNode = create_node(NewData);
	if (NewNode == NULL) return (NewNode);
	if (*Tree == NULL)
		*Tree = NewNode;
	else{
		node_type *Rnode = *Tree;
		while (Rnode->right != NULL)
			Rnode = Rnode->right;
		Rnode->right = NewNode;
	}
	return (NewNode);
}

void freeTree(treetype tree){
  if (tree != NULL)
  free(tree->left);
  free(tree->left);
  free((void*)tree);
}

int treeHeight(treetype t) {
  // your code here
  if( t == NULL) return 0;

  int leftH = treeHeight(LeftChild(t));
  int rightH = treeHeight(RightChild(t));
  int maxHeight = 1+((leftH > rightH) ? leftH : rightH);
  return maxHeight;
}
int treeNbrLeaf(treetype t) {
  // your code here
}
int treeInternalNode(treetype t) { 
  // your code here 
}

int treeNbrRightChildren(treetype t) {
  // your code here
  // right != NULL thi tinh
  if (isEmptyTree(t))
    return 0;
  else{
    if (t->right != NULL)
      return 1 + treeNbrRightChildren(t -> right) + treeNbrRightChildren(t->left);
    else
      return treeNbrRightChildren(t->left);}
}

int main() {
  treetype tr;
  makeNullTree(&tr);
  if (isEmptyTree(tr)) printf("Empty Tree\n");

    elmType giaithua = {'!', 0};
    elmType chia = {'/', 0};
    elmType tru = {'-', 0};
    elmType cong = {'+', 0};
    elmType a = {' ', 10};
    elmType b = {' ', 3};
    elmType c = {' ', 4};
    elmType d = {' ', 2};

    tr = create_node(cong);
    tr = Add_Left(tr, giaithua);
    tr = Add_Left(tr -> left,a);

    tr = Add_Right(tr, chia);
    tr = Add_Right(tr -> right, d);
    tr = Add_Right(tr -> right, tru);
    tr = Add_Right(tr -> right -> left,b);
    tr = Add_Right(tr -> right -> left,c);

//   for (int i = 0; i < 4; i++) 
    // Add_Left(&tr, 10+i);
//   for (int i = 0; i < 5; i++) 
    // Add_Right(&tr, 100+i);

  // tr = createfrom2(1000, tr, tr);
//   printf("So nut la: %d\n", nb_nodes(RightChild(tr)));
//   printf("Tree Height: %d\n", treeHeight(tr));
//   printf("So la: %d\n", treeNbrLeaf(tr));
//   printf("# internal node: %d\n", treeInternalNode(tr));
//   printf("# right children: %d\n", treeNbrRightChildren(tr));

  free(tr);
  return 0;
}