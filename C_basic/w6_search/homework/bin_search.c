#include <stdio.h>
#define NOT_FOUND (-1)

int Bin_search(int T[], int key, int low, int high){
    if (low > high) return NOT_FOUND;
    int mid = (low + high)/2;
    if (T[mid] > key ) return Bin_search(T, key, low, mid -1);
    else if (T[mid] < key ) return Bin_search(T, key, mid +1, high);
    else return mid;
    return NOT_FOUND;
}

int main(void){
    int T[] = {1,2,3,4,5,6,8,9,14,23,40};
    int key=3;
    printf("Vi tri cua %d la index %d\n", key, Bin_search(T,key,0,sizeof(T)/sizeof(T[0])-1));
    return 0;
}