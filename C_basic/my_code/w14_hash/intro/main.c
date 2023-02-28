#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"

element_t ht[TABLE_SIZE];
//hash table

int main() {
  const char* keys[] = {"John Smith", "Lisa Smith", "Sam Doe", "Sandra Dee"};

  printf("Start\n");
  for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
    printf("(key, hash(key)) = (%s, %d)\n", keys[i], hash(keys[i]));
  }

  init_table(ht);
  for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
    element_t e;
    strcpy(e.key, keys[i]);
    strcpy(e.word, keys[i]);
    insertItem(ht, e);
  }

  // element_t f;
  // strcpy(f.key,keys[3]);
  // strcpy(f.word,keys[3]);
  // insertItem(ht, f);

  // element_t e;
  // strcpy(e.key,keys[0]);
  // strcpy(e.word,keys[0]);
  // insertItem(ht, e);

  printf("Traverse:\n");
  traverse(ht);

  return 0;
}