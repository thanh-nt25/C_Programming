#include <stdio.h>
#define NOT_FOUND (-1)
typedef int T;

int binarySearch(T a[], const int n, const T key) {
  int low = 0;
  int high = n - 1;
  int mid = (low + high) / 2;

  for (; low <= high; mid = (low + high) / 2) {
    if (a[mid] == key)
      return mid;
    else if (a[mid] < key)  // <---
      low = mid + 1;
    else  // (key < a[mid]) // <---
      high = mid - 1;
  }
  return NOT_FOUND; /* NotFound is defined as -1 */
}

int main() {
  int a[] = {1, 3, 5, 7, 9, 13, 15};
  int key = 5;

  for (int i = 0; i < 20; i++) {
    printf("BinarySearch of %d returns %d\n", key,
           binarySearch(a, key, sizeof(a) / sizeof(a[0])));
  }
  return 0;
}