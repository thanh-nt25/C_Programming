// Exercise 14.4: ADT Hash Table with quadratic probing method


#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE (7)
#define NULLKEY (-1)

typedef struct node_t {
  int key;
  /* other fields */
} element_t;

void init_table();
int hashfunc(const int k);

int findElement(const int k);
int insertItem(const int k);
// int removeElement(int k);

void traverse();  // Duyet