#ifndef __SORT_T_H__
#define __SORT_T_H__

#include "data_t.h"

typedef data_t T;

void insertion_sort(T a[], const int n);
void selection_sort(T a[], const int n);
void heapsort(T lst[], const int n);
void quicksort(T list[], const int left, const int right);

#endif