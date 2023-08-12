#include <stdio.h>
#include <string.h>
#include "data_t.h"

void showData(data_t data) {
  printf("%s\n", data.words);
}
// data_t convert(int number) { return number; }
data_t convert(char *word){
  data_t tmp;
  strcpy(tmp.words, word);
  return tmp;
}


// equal
int eq(const keyT key, const data_t* dat) {
  return (strcmp(key, dat->words) == 0);
}

// less than
int lt(const keyT key, const data_t* dat) {
  return (strcmp(key, dat->words) < 0);
}

// great than
int gt(const keyT key, const data_t* dat) {
  return (strcmp(key, dat->words) > 0);
}