#ifndef __DATA_T_H__
#define __DATA_T_H__

typedef struct cp_s{
    char ma[4];
    float mocua;
    float dongcua;
}   cp_t;

// typedef int data_t;
typedef cp_t data_t;
// typedef int keyT;  // to find
typedef char* keyT;

void showData(data_t data);
// data_t convert(int number);
data_t convert(char ma[], float mocua, float dongcua);

int eq(const keyT key, const data_t* dat);
// less than
int lt(const keyT key, const data_t* dat);
// great than
int gt(const keyT key, const data_t* dat);

#endif