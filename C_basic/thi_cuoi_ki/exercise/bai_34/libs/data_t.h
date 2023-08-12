#ifndef __DATA_T_H__
#define __DATA_T_H__

// ĐỔI CẤU TRÚC BỘ DỮ LIỆU + TÊN
typedef struct word_s{
    char Eng[21];
    char Viet[21];
}   word_t;

typedef word_t data_t;

// typedef int keyT;  // to find
// THAY ĐỔI KEY DÙNG ĐỂ SO SÁNH
typedef char* keyT;

void showData(data_t data);
// data_t convert(int number);
data_t convert(char *End, char *Viet);

int eq(const keyT key, const data_t* dat);
// less than
int lt(const keyT key, const data_t* dat);
// great than
int gt(const keyT key, const data_t* dat);

#endif