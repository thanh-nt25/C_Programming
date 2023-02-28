#include "hash.h"

#include <string.h>

element_t *D[TABLE_SIZE];  // <===

// Hash Code Maps
// Component Sum
static const int transform(const char *key) {
  int number;
  for (number = 0; (*key) != 0; key++) number += *key;
  return number;
}

// Compression map
int hash(const char *key) { return (transform(key) % TABLE_SIZE); }

// ====================================
//
// ====================================

void init_table(element_t *ht[]) {  // <===
  clear(ht);
}

void clear(element_t *ht[]) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    clearbucket(ht, i);
  }
}

// hàm xóa 1 bucket
void clearbucket(element_t *ht[], int b) {
  element_t *p;
  p = ht[b];
  while(p != NULL){
    element_t *q = p;
    p  = p -> next;
    free(q);
  }
  ht[b] == NULL;
}

// tìm 1 phần tử key (trả về FALSE nếu ko tìm thấy)
element_t *findElement(element_t *ht[], char key[]) {
  const int hash_value = hash(key);
  if (ht[hash_value] == NULL)
    return NULL;
  else {
    element_t *p = NULL;
    p = ht[hash_value];
    while(p != NULL){
      if (strcmp(p->key,key) == 0) return p;
      else p = p->next;
    }
  }
  return FALSE;
}

int insertItem(element_t *ht[], element_t o) {
  int hash_value = hash(o.key);
  element_t *pNewElement = (element_t *)malloc(sizeof(element_t) * 1);
  strcpy(pNewElement->key, o.key);
  strcpy(pNewElement->word, o.word);
  pNewElement->next = NULL;

  if (ht[hash_value] == NULL) {
    ht[hash_value] = pNewElement;
    return TRUE;
  } else {
    // your code here
    element_t *q = NULL;
    for(q = ht[hash_value]; q -> next != NULL; q = q->next);
    q -> next = pNewElement;
    return TRUE;
  }
}

void traverse(element_t *ht[]) {
  for (int b = 0; b < TABLE_SIZE; b++) {
    printf("\nBucket %d", b);
    _traversebucket(ht, b);
  }
}

// hàm in các phần tử trong bucket
void _traversebucket(element_t *ht[], int b) {
  element_t *p;
  p = ht[b];
  // in các phần tử trong danh sách liên kết của bucket
  while(p  != NULL){
    printf(" -> ");
    printf("(%s, %s)", p->key, p->word );
    p = p -> next;
  }
  printf("\n");
}

// hàm xóa 1 phần tử key
int removeElement(element_t *ht[], char key[]) {
  int hash_value = hash(key), Done;
  element_t *p1 = ht[hash_value];
  element_t *q = NULL;

  if (p1 == NULL)
    return -1;  // khong tim thay
  else {
    // nếu phần tử cần tìm ở ngay đầu bucket
    if(strcmp(ht[hash_value]->key,key) == 0){
      ht[hash_value] = ht[hash_value] -> next;
      free(p1);
    } else {
      Done = 0;
      // duyệt để tìm phần tử trong danh sách liên kết
      while((p1->next != NULL) && (!Done)){
        if(strcmp(p1 -> next -> key, key) == 0) Done = 1;
        else p1 = p1 -> next;
      }
      // xóa phần tử đó
      if (Done){
        q = p1 -> next;
        p1 -> next = q->next;
        free(q);
      }
    }
  }
}

int isEmpty(element_t *ht[]) {
  for (int i = 0; i < TABLE_SIZE; i++)
    if (ht[i] != NULL) return FALSE;
  return TRUE;
};
