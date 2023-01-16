#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

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