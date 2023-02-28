#include <stdio.h>
#include <string.h>
#include "data_t.h"

void showData(data_t data) {
  printf("%s - %s\n", data.Eng, data.Viet);
}
// data_t convert(int number) { return number; }
data_t convert(char *Eng, char *Viet){
  data_t tmp;
  strcpy(tmp.Eng, Eng);
  strcpy(tmp.Viet, Viet);
  return tmp;
}


// equal
int eq(const keyT key, const data_t* dat) {
  return (strcmp(key, dat->Eng) == 0);
}

// less than
int lt(const keyT key, const data_t* dat) {
  return (strcmp(key, dat->Eng) < 0);
}

// great than
int gt(const keyT key, const data_t* dat) {
  return (strcmp(key, dat->Eng) > 0);
}