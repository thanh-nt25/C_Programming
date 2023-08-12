#include <stdio.h>
#include "data_h.h"

void showdata(data_t data){
    printf("%d\n", data);
}

data_t convert(int num){
    return num;
}

int eq(data_t data, const keyT dat){
    return (data = dat);
}

int lt(data_t data, const keyT dat){
    return (data < dat);
}

int gt(data_t data, const keyT dat){
    return (data > dat);
}