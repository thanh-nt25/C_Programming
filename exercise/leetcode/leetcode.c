#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *twosum(int *nums, int numsSize, int target, int *returnSize){
    for ( int i=0; i<numsSize; ++i){
        if((nums[i] + nums[i+1]) == target){
            returnSize = (int *)malloc((sizeof(numsSize) / sizeof(nums[0])) * 2);
            *returnSize = i;
            *(returnSize + 1) = i+1;
            return returnSize;
        }
    }
}

int main(void){
    int nums[] = {3,5,6,2,4,5,6};
    int *arr = twosum(nums, sizeof(nums), 6, arr);
    printf("%d\n", arr[0]);                     
    printf("%d\n", arr[1]);    
    return 0;
}