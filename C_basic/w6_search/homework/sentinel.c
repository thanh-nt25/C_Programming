/* cho mang T co N phan tu,
    truy xuat vi tri i cua phan tu X 
    => Su dung dat linh canh 
*/

#include <stdio.h>

int Linear_sentinel_s(int T[], int N, int X){
    int k = 0; T[N] = X;
    while( T[k] != X) ++k;
    return k;
}

int main(void){
    int T[5] = {1,2,3,4,5};
    int index = Linear_sentinel_s(T, 5, 3);
    if ( index == 5 ) printf("Not found! \n");
    else printf("Index is: %d \n", index);
    return 0;
}