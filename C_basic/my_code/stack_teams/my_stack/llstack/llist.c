#include <stdio.h>
#include <string.h>
#include "llist.h"

root_t Init(){ return NULL; }

node_t *createNode(const data_t data){
    node_t* newnode = (node_t *)malloc(sizeof(node_t));
    if( newnode == NULL ) return NULL;
    newnode -> data = data;
    newnode -> next = NULL;
    return newnode;
}

root_t llPrint(root_t root){
    for(node_t *q = root; q != NULL; q = q -> next){
        showdata(q->data);
    }
    printf("\n");
    return root;
}

node_t *llSeek(root_t root, int index){
    node_t *q = NULL;
    for(q=root; index > 0 && (q != NULL); index--) q=q->next;
    return q;
}

/*================= Insert ====================*/ 

root_t llInsertHead(root_t root, const data_t data){
    node_t *newnode = createNode(data);
    if (root == NULL) return newnode;
    newnode -> next = root;
    return (root_t)newnode;
}

root_t llInsertTail(root_t root, const data_t data){
    node_t *newnode = createNode(data);
    if (root == NULL) return newnode;
    node_t *q;
    for(q = root; q -> next != NULL;) q = q->next;
    q -> next = newnode;
    return root;
}

root_t llInsertAfter(root_t root, data_t data, node_t *pAElem){
    if(pAElem == NULL) return root;
    node_t* newnode = createNode(data);
    if(root == NULL) return newnode;
    newnode-> next = pAElem->next;
    pAElem -> next = newnode;
    return root;
}

/*================== Delete =====================*/ 

root_t llDeleteHead(root_t root){
    if (root == NULL) return NULL;

    node_t *p = root -> next;
    free(root);
    return p;
}

root_t llDeleteTail(root_t root){
    if(root == NULL) return NULL;
    if(root->next == NULL){
        free(root);
        return NULL;
    }
    node_t *q = NULL;
    for(q = root; q -> next -> next != NULL; q=q->next);

    free(q->next);
    q->next= NULL;
    return (root_t)root;
}

root_t llDeleteAfter(root_t root, node_t* pA) {
  if ((pA == NULL) || (pA->next == NULL)) return root;

  node_t* pToDelElem = pA->next;
  pA->next = pA->next->next;

  free(pToDelElem);
  return root;
}

root_t llDeleteAll(root_t root) {
  node_t* p = NULL;
  for (; root != NULL; root = p) {
    p = root->next;
    free(root);
  }
  return NULL;
}

/* === Tools ========================================= */
int llLength(root_t root) {
  int count;
  for (count = 0; root!=NULL; root = root->next) count++;
  return count;
}

// to check
root_t reverseLL(root_t root) {
  node_t *cur, *prev;

  for (cur = prev = NULL; root != NULL;) {
    cur = root;
    root = root->next;
    cur->next = prev;
    prev = cur;
  }
  // to check
  return root;
}
