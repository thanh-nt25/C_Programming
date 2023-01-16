#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sortChar.h"

int main() {
  char a[] = "aljsdlfjkdlfjlsear";
  char b[] = "aljsdlfjkdlfjlsear";
  char c[] = "aljsdlfjkdlfjlsear";

  printf("\n--- Insertion Sort ---\n");
  printf("String: %s\n", a);
  insertion_sort(a, strlen(a));
  printf("result: %s\n", a);

  printf("\n--- Selection Sort ---\n");
  printf("String: %s\n", b);
  selection_sort(b, strlen(b));
  printf("result: %s\n", b);

  printf("\n--- Heap Sort ---\n");
  printf("String: %s\n", c);
  heapsort(c, strlen(c));
  printf("result: %s\n", c);

  return EXIT_SUCCESS;
}