// https://code.visualstudio.com/docs/cpp/config-linux
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "ll.h"

// Must Adapt to new problem
typedef struct {
  // int id;
  char id[16];
  char name[40];
  int grade;
} data_t;

// root (or head)
// Cur: Pointer variable that keeps the element just now
typedef struct node_s {
  data_t data;
  struct node_s *next;
} node_t, *root_t;

// Must Adapt to new problem
// void showData(const data_t data);

// root_t llPrint(root_t root);

// root_t llInit();
// node_t *llSeek(root_t root, int index);

// root_t llInsertHead(root_t root, const data_t data);
// root_t llInsertTail(root_t root, const data_t data);
// root_t llInsertAfter(root_t root, node_t *pAElem, const data_t data);

// root_t llDeleteHead(root_t root);
// root_t llDeleteTail(root_t root);
// root_t llDeleteAfter(root_t root, node_t *pA);
// root_t llDeleteAll(root_t root);

// // Tools
// int llLength(root_t root);
// root_t reversell(root_t root);



void showData(data_t data) { 
  // printf("%d ", data.id);
  printf("%s - %s - %d\n", data.id, data.name, data.grade);
}

// Traversing a list and show
root_t llPrint(root_t root) {
  for (node_t* p = root; p != NULL; p = p->next) showData(p->data);
  printf("\n");
  return root;
}

// Create a new Node
// return:
//  - on SUCCESS: return a pointer to new Node
//  - on FAIL   : return a NULL pointer
node_t* createNewNode(const data_t data) {
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  if (newNode == NULL) return NULL;

  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

root_t llInit() { return NULL; }

node_t* llSeek(root_t root, int index) {
  node_t* p;
  for (p = root; index > 0 && (p != NULL); index--) p = p->next;
  return p;
}

/* === Insert ============================================== */

root_t llInsertHead(root_t root, const data_t data) {
  node_t* pNewNode = createNewNode(data);
  pNewNode->next = root;
  return (root_t)pNewNode;
}

root_t llInsertTail(root_t root, const data_t data) {
  node_t* pNewNode = createNewNode(data);

  if (root == NULL) return (root_t)pNewNode;

  node_t* p = NULL;
  for (p = root; p->next != NULL; p = p->next)
    ;
  p->next = pNewNode;
  return root;
}

root_t llInsertAfter(root_t root, node_t* pAElem, const data_t data) {
  if (pAElem == NULL) return root;

  node_t* pNewNode = createNewNode(data);
  pNewNode->next = pAElem->next;
  pAElem->next = pNewNode;

  return root;
}

/* === Delete ============================================== */

root_t llDeleteHead(root_t root) {
  if (root == NULL) return NULL;

  node_t* p = root->next;
  free(root);
  return (root_t)p;
}

root_t llDeleteTail(root_t root) {
  if (root == NULL) return NULL;
  if (root->next == NULL) {
    free(root);
    return NULL;
  }

  node_t* p;
  // Find previous node of Tail
  for (p = root; p->next->next != NULL; p = p->next)
    ;

  free(p->next);
  p->next = NULL;
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


// data_t convert(int i) {
  // data_t data = {i};
  // return data;
// }
data_t convert(char id[], char name[], int grade) {
  data_t data;
  strcpy(data.id, id);
  strcpy(data.name, name);
  data.grade = grade;
  return data;
}



/*================ Main funtion ========================*/

int main() {
  data_t sv1 = {"001", "sv1", 2};
  data_t sv2 = {"002", "sv2", 4};
  data_t sv3 = {"003", "sv3", 6};
  data_t sv4 = {"004", "sv4", 8};
  data_t sv5 = {"005", "sv5", 10};
  data_t aSV[] = {{"001", "sv1", 2},
                  {"002", "sv2", 4},
                  {"003", "sv3", 6},
                  {"004", "sv4", 8},
                  {"005", "sv5", 10}};

  root_t lst = llInit();
  for (int i = 0; i < sizeof(aSV) / sizeof(aSV[0]); i++)
    lst = llInsertHead(lst, aSV[i]);
  // lst = llInsertHead(lst, sv2);
  // lst = llInsertHead(lst, sv3);
  // lst = llInsertHead(lst, sv4);
  // lst = llInsertHead(lst, sv5);

  // for (int i = 0; i < 5; i++) {
  //   lst = llInsertTail(lst, convert(i));
  //   lst = llInsertHead(lst, convert(-i));
  // }
  llPrint(lst);

  // node_t *p = llSeek(lst, 0);
  // lst = llDeleteAfter(lst, p);
  lst = llDeleteHead(lst);
  lst = llDeleteTail(lst);

  llPrint(lst);

  lst = llDeleteAll(lst);

  return 0;
}