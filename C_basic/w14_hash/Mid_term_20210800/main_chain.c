#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

element_t* ht[TABLE_SIZE];

int main() {
  char* keys[] = {"John Smith", "Lisa Smith", "Sam Doe", "Sandra Dee",
                   "Sam Smith", "Tuan Thanh"};
  // const char* keys[] = {"John Smith", "Lisa Smith", "Sam Doe"};
  // const char* keys[] = {"Lisa Smith", "Sandra Dee"};

  for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
    printf("(hash(key), key) = (%d, %s)\n", hash(keys[i]), keys[i]);
  }

  init_table(ht);
  for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
    element_t e;
    strcpy(e.key, keys[i]);
    strcpy(e.word, keys[i]);
    e.next = NULL;
    insertItem(ht, e);
  }

  printf("\n-------------\nTraverse:\n");

  traverse(ht);

  removeElement(ht, keys[0]);
  removeElement(ht, keys[2]);
  removeElement(ht, keys[3]);

  printf("\n-------------\nTraverse after removed \"%s\" (3), \"%s\" (6), \"%s\" (12):\n", 
            keys[2], keys[3], keys[0]);
  traverse(ht);

  return 0;
}