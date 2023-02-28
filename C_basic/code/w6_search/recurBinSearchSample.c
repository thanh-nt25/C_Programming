#include <stdio.h>
#define NOT_FOUND (-1)
typedef int T;

// Usage: recursiveBinarySearch(A, X, 0, size - 1)
int recursiveBinarySearch(T a[], T key, int low, int high) {
  if (low > high) return NOT_FOUND;

  int mid = (low + high) / 2;
  if (a[mid] < key)
    return recursiveBinarySearch(a, key, mid + 1, high);
  else if (a[mid] > key)
    return recursiveBinarySearch(a, key, low, mid - 1);
  else
    return mid; /* Found */

  return NOT_FOUND; /* NotFound is defined as -1 */
}

int main() {
  static int A[] = {1, 3, 5, 7, 9, 13, 15};
  for (int i = 0; i < 20; i++) {
    printf("BinarySearch of %d returns %d\n", i,
           recursiveBinarySearch(A, i, 0, sizeof(A) / sizeof(A[0]) - 1));
  }
  return 0;
}