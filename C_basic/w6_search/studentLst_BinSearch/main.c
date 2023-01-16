#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENT (100)
#define NOT_FOUND (-1)

typedef struct phoneAddr_s {
  union {
    char name[20];
    char key[20];
  };
  char tel[20];
  char email[32];
} phoneAddr_t;

typedef phoneAddr_t T;

int binarySearch(T a[], const int n, const char* key) {
  int low = 0;
  int high = n - 1;

  for (int mid = (low + high) / 2; low <= high; mid = (low + high) / 2) {
    if (strcmp(a[mid].key, key) == 0)
      return mid;
    else if (strcmp(a[mid].key, key) < 0)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return NOT_FOUND; /* NotFound is defined as -1 */
}

int main() {
  char key[] = "B";

  phoneAddr_t a[MAX_ELEMENT] = {{"A", "1", "1@"},
                                {"B", "2", "2@"},
                                {"C", "3", "3@"},
                                {"D", "4", "4@"},
                                {"E", "5", "5@"}};

  printf("BinarySearch of %s returns %d\n", key, binarySearch(a, 5, key));

  return 0;
}