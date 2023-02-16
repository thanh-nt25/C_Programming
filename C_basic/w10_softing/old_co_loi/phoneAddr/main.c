#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "sort_t.h"

int main() {
  phoneAddr_t phoneArr[10] = {{"X", "0", "f@g"}, {"B", "1", "b@g"},
                              {"Y", "2", "c@g"}, {"D", "3", "d@g"},
                              {"E", "4", "e@g"}, {"A", "5", "a@g"},
                              {"G", "6", "g@g"}, {"H", "7", "h@g"},
                              {"I", "8", "i@g"}, {"J", "9", "j@g"}};
  
  const int N = sizeof(phoneArr) / sizeof(phoneArr[0]);

  printf("\n--- Origin ---\n");
  for (int i = 0; i < N; i++) showData(phoneArr[i]);

  printf("\n\n--- quicksort ---");
  quicksort(phoneArr, 0, N - 1);
  for (int i = 0; i < N; i++) showData(phoneArr[i]);

  return EXIT_SUCCESS;
}