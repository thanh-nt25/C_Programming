#ifndef __DATA_H__
#define __DATA_H__

#include <stdio.h>

typedef int eleType;
typedef eleType data_t;

typedef int keyT;

void showdata(data_t data);
data_t convert(int num);

int eq(data_t data, const keyT dat);
int lt(data_t data, const keyT dat);
int gt(data_t data, const keyT dat);

#endif