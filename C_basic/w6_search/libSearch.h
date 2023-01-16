#ifndef __LIB_SEARCH_H__
#define __LIB_SEARCH_H__

#define NOT_FOUND (-1)

typedef char T;
typedef char key_T;

int linearSearch(T M[], const int n, const key_T key);
int linearSentinelSearch(T M[], const int n, const key_T key);
int searchMTF(T r[], const int n, const key_T key);

#endif