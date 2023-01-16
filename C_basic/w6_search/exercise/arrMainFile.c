#include <stdio.h>
#include <string.h>

#include "../data_t.h"
#include "../mFile.h"

#define NOT_FOUND -1

typedef phoneAddr_t T;

// return index of items where items[index] == key
int linearSearchStr(T items[], int siz, char name2Find[]) {
  for (int i = 0; i < siz; i++)
    if (strcmp(items[i].name, name2Find) == 0) return i;
  return NOT_FOUND;  // no match
}

int main() {
  const char fname[] = "../test.dat";
  phoneAddr_t a[100];
  
  int n = readFromFile(fname, a, sizeof(a) / sizeof(a[0]));
  showAllData(a, n);

  int index = linearSearchStr(a, sizeof(a) / sizeof(a[0]), "B");

  if (index == NOT_FOUND)
    printf("Not found\n");
  else {
    printf("Found. Index = %d\n", index);
    showData(a[index]);
    write2File("result.dat", &a[index], 1);

    // check
    phoneAddr_t buf[1];
    readFromFile("result.dat", buf, 1);
    showData(buf[0]);
  }  

  return 0;
}