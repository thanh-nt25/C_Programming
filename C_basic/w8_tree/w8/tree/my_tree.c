#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int elmType;

typedef struct nodeType{
    elmType element;
    struct nodeType *left, *right;
} node_type;

typedef struct nodeType *treetype;

/*================== functions ========================*/

void makeNulltree(treetype *T) {(*T) = NULL;}
// check xem cay co rong ko - tra lai bieu thuc 1 0
// 1: cay rong / 0: cay co du lieu
int isEmptytree(treetype T) { return T == NULL; }

treetype LeftChild(treetype n){
    if ( n != NULL )
        return n->left;
    else
        return NULL;
}

treetype RightChild(treetype n){
    if( n != NULL )
        return n->right;
    else
        return NULL;
}

node_type *createNode(elmType NewData){
    node_type *N = (node_type *)malloc(sizeof(node_type));
    if (N != NULL){
        N -> element = NewData;
        N -> right = NULL;
        N -> left = NULL;
    }
    return N;
}

// tra lai bieu thuc logic
int IsLeaf(treetype n){
    if (n != NULL)
        return (LeftChild(n) == NULL) && (RightChild(n) == NULL);
    else
        return -1;
}

int nb_nodes(treetype T){
    if(isEmptytree(T))
        return 0;
    else
        // so nut trai + so nut phai
        return 1 + nb_nodes(LeftChild(T)) + nb_nodes(RightChild(T));
}


