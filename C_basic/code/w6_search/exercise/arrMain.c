#include <stdio.h>
#include <string.h>

#include "../data_t.h"

#define NOT_FOUND -1

typedef phoneAddr_t T;

// return index of items where items[index] == key
int linearSearchStr(T items[], int siz, char name2Find[]) {
  for (int i = 0; i < siz; i++)
    if (strcmp(items[i].name, name2Find) == 0) return i;
  return NOT_FOUND;  // no match
}

int main() {
  phoneAddr_t a[] = {{"A", "1", "1@"},
                     {"B", "2", "2@"},
                     {"C", "3", "3@"},
                     {"D", "4", "4@"},
                     {"E", "5", "5@"}};

  int index = linearSearchStr(a, sizeof(a) / sizeof(a[0]), "B");

  if (index == NOT_FOUND)
    printf("Not found\n");
  else {
    printf("Found. Index = %d\n", index);
    showData(a[index]);
  }

  return 0;
}