#include <stdio.h>
#include <string.h>
#include "data_t.h"

void showData(data_t data) {
  printf("%s %g %g\n", data.ma, data.mocua, data.dongcua);
}
// data_t convert(int number) { return number; }
data_t convert(char ma[], float mocua, float dongcua){
  data_t tmp;
  strcpy(tmp.ma, ma);
  tmp.mocua = mocua;
  tmp.dongcua = dongcua;
  return tmp;
}


// equal
int eq(const keyT key, const data_t* dat) {
  return (strcmp(key, dat->ma) == 0);
}

// less than
int lt(const keyT key, const data_t* dat) {
  return (strcmp(key, dat->ma) < 0);
}

// great than
int gt(const keyT key, const data_t* dat) {
  return (strcmp(key, dat->ma) > 0);
}