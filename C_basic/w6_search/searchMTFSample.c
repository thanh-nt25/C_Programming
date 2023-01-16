#include <stdio.h>
#include <string.h>

typedef char T;

int searchMTF(T r[], int n, T key);

int searchMTF(T r[], int n, T key) {
  int i, j;
  T tempr;
  for (i = 0; i < n - 1 && r[i] != key; i++)
    ;
  if (key == r[i]) {
    // Đảo phần tử tìm thấy lên đầu
    // Các phần tử sau phần tử tìm thấy giữa nguyên vị trí
    // Các phần tử trước dịch lùi 1 vị trí
    if (i > 0) {  
      tempr = r[i];
      for (j = 0; j < i; j++) // Dồn i phần tử đầu về sau 1 vị trí
        r[j + 1] = r[j];
      r[0] = tempr;
    };
    return (i); // trả về chỉ số vị trí cũ. Dữ liệu cũ luôn ở đầu mảng
  } else
    return (-1);
}

int main(void) {
  char str[20] = "asdf";
  int index = searchMTF(str, strlen(str), 'd');
  printf("%d", index);

  return 0;
}