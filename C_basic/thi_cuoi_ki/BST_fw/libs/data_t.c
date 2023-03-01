#include <stdio.h>
#include <string.h>
#include "data_t.h"

// THAY ĐỔI IN DỮ LIỆU
void showData(data_t data) {
  // printf("%s - %s\n", data.Eng, data.Viet);
}
// data_t convert(int number) { return number; }
// THAY ĐỔI THEO CẤU TRÚC DỮ LIỆU
data_t convert(char *Eng, char *Viet){
  data_t tmp;
  strcpy(tmp.Eng, Eng);
  strcpy(tmp.Viet, Viet);
  return tmp;
}


// equal
int eq(const keyT key, const data_t* dat) {
  return (strcmp(key, dat->Eng) == 0); // THAY ĐỔI TRƯỜNG SO SÁNH
}

// less than
int lt(const keyT key, const data_t* dat) {
  return (strcmp(key, dat->Eng) < 0); // THAY ĐỔI TRƯỜNG SO SÁNH
}

// great than
int gt(const keyT key, const data_t* dat) {
  return (strcmp(key, dat->Eng) > 0); // THAY ĐỔI TRƯỜNG SO SÁNH
}