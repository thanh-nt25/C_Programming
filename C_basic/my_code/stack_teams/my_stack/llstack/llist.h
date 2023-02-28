#ifndef __LLIST_H__
#define __LLIST_H__

#include <string.h>
#include "data_t.h"

typedef struct node_s{
    data_t data;
    struct node_s *next;
}   node_t, *root_t; //de thao tac voi con tro


root_t Init();
node_t *createNode(const data_t data);
root_t llPrint(root_t root);
node_t *llSeek(root_t root, int index);


root_t llInsertHead(root_t root, const data_t data);
root_t llInsertTail(root_t root, const data_t data);
root_t llInsertAfter(root_t root, data_t data, node_t *pAElem);

root_t llDeleteHead(root_t root);
root_t llDeleteTail(root_t root);
root_t llDeleteAfter(root_t root, node_t* pA);
root_t llDeleteAll(root_t root);

int llLength(root_t root);
root_t reverseLL(root_t root);

#endif