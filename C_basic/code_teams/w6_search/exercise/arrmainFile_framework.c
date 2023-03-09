#include <stdio.h>
#include <string.h>

#include "../data_t.h"
#include "../mFile.h"

#define NOT_FOUND -1

typedef phoneAddr_t T;

// TODO: 
// return index of items where items[index] == key
int linearSearchStr(T items[], int siz, char name2Find[]) {
  for (...; ...; ...)
    if (...) == 0) 
      return ...;
  return NOT_FOUND;  // no match
}

int main() {
  const char fname[] = "../test.dat";
  phoneAddr_t a[100];
  
  int n = readFromFile(fname, a, ... ));
  showAllData(a, n);

  int index = linearSearchStr(a, ..., "B");

  if (index == NOT_FOUND)
    printf("Not found\n");
  else {
    printf("Found. Index = %d\n", index);
    showData(a[index]);
    write2File("result.dat", ... , ...);

    // check
    phoneAddr_t buf[1];
    readFromFile("result.dat", ..., ...);
    showData(buf[0]);
  }  

  return 0;
}