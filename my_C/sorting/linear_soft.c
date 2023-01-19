#include <stdio.h>

void print_arr(int arr[], int n){
    for (int i=0; i<n; ++i){
        printf("%d \t", arr[i]);
    }
    printf("\n");
}

int main(void){
    int arr[] = {2,3,4,1,6,5,8,10,9};
    print_arr(arr, sizeof(arr)/sizeof(arr[0]));
    int temp;
    for(int i=0; i<(sizeof(arr)/sizeof(arr[0])-1); ++i){
        if (arr[i] > arr[i+1]){
            temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
    print_arr(arr, sizeof(arr)/sizeof(arr[0]));
    
    return 0;
}