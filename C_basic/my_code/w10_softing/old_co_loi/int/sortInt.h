#ifndef __SORTCHAR_H__
#define __SORTCHAR_H__

#include <string.h>
#include <stdlib.h>

typedef int T;

void insertion_sort(T a[], const int n);
void selection_sort(T a[], const int n);
void sortHeap(T lst[], const int n);
void quicksort(T list[], int left, int right);
void mergeSort(T a[], const int n);

#endif