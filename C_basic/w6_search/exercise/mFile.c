#include <stdio.h>
#include <stdlib.h>
#include "data_t.h"
#include "mFile.h"


// Giả sử dữ liệu chỉ cần đọc viết 1 lần lần (kích thước của buf đủ để chứa toàn bộ dữ
// liệu đọc từ file)
void write2File(const char fname[], const data_t buf[], const int n) {
  FILE *fp;

  fp = fopen(fname, "wb");
  if (fp == NULL) {
    printf("Cannot open test.dat file. \n");
    exit(1);
  }

  fwrite(buf, sizeof(buf[0]), n, fp);

  fclose(fp);
}

// Trả về số phần tử đọc được
// Dữ liệu được chứa trong buf, buf phải được cấp phát trước ngoài hàm 
int readFromFile(const char fn[], data_t buf[], int elemNbr) {
  FILE *fp;

  fp = fopen(fn, "rb");
  if (fp == NULL) {
    printf("Cannot open test.dat file.\n");
    exit(1);
  }
  int siz = sizeof(data_t);

  int n = fread(buf, sizeof(data_t), elemNbr, fp);
  fclose(fp);
  return n;
}