#ifndef __DATA_T_H__
#define __DATA_T_H__

typedef struct word_s{
    char Eng[21];
    char Viet[21];
}   word_t;

// typedef int data_t;
typedef word_t data_t;
// typedef int keyT;  // to find
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