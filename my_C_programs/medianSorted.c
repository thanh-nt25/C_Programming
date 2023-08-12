#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(char *s, int i , int j){
    for (int p = i; p < j; ++p){
        for (int q = p + 1; q <= j; ++q){
            if (s[p] == s[q]){
                return -1;}
        }
    }
    return 0;
}

int lengthOfLongestSubstring(char * s){
    int length = 0;
    for (int i=0; i < (strlen(s)-1); ++i){
        for (int j=i+1; j < strlen(s); ++j){
            if((compare(s, i, j) == 0) && (length < (j-i+1)) ) length = j-i+1;
        }
    }
    return length;
}

void swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void Sorted(int *arr, int length){
     // sorted
    for(int i=0; i < (length-1); ++i){
        for(int j=i+1; j < length; ++j){
            if(arr[j] < arr[i]) swap(&arr[j], &arr[i]);
        }
    }
}
double rt_func(int *arr, int length){
    if((length % 2) == 1) return (double)arr[length/2];
    if((length % 2) == 0) return (double)((double)(arr[length/2]+arr[length/2-1]) / 2);
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    if(nums1Size == 0){
        Sorted(nums2, nums2Size);
        return rt_func(nums2, nums2Size);
    } else if(nums2Size == 0){
        Sorted(nums2, nums2Size);
        return rt_func(nums2, nums2Size);
    }
    else{
    int merge_arr[nums1Size + nums2Size];
    int m = nums1Size - 1; // =1
    int n = nums2Size - 1; // =1
    int length = nums1Size + nums2Size; //=4

    for ( int i=0; i < length; ++i){
        if(i <= m){ // <= 1, 0->1
            merge_arr[i] = nums1[i];
        }
        if(i > m){ // i= 2, 2->3, 0->1
            merge_arr[i] = nums2[i-nums1Size];
        }
    }
    Sorted(merge_arr, length);
    return rt_func(merge_arr, length);
    // for(int i=0; i<length; ++i){ printf("%d\n", merge_arr[i]);}
    }
    return 0;
}

int reverse_str(char *str){
    char cmpStr[strlen(str)+1];
    for (int i=0; i <= strlen(str); ++i){
        cmpStr[i] = str[strlen(str) - i - 1];
    }
    return (strcmp(cmpStr, str) == 0);
}

char * substring(char *s, int i, int j){
    char *sub = (char *)malloc(sizeof(char)*(j-i+1+1));
    for(int k=i; k<=j; ++k){
        sub[k] = s[k];
    }
    // printf("%s\n", sub);
    return sub;
}

char * longestPalindrome(char * s){
    int max = 0;
    char *max_sub;
    for (int i=0; i < (strlen(s)-1); ++i){
        for(int j=i+1; j < strlen(s); ++j){
            char *sub_mem = substring(s,i,j);
            // printf("true\n");
            if((reverse_str(sub_mem) == 1) && (max < (j-i+1))){
                max = j-i+1;
                max_sub = substring(s,i,j);
            }
        }
    }
    return max_sub;
}

int main(void){
    // char *s = "ghahsndha";
    // printf("Max sub: %d\n", lengthOfLongestSubstring(s));
    // int nums1[] = {};
    // int nums2[] = {1};
    // int m = sizeof(nums1)/sizeof(nums1[0]);
    // int n = sizeof(nums2)/sizeof(nums2[0]);
    char *s = "babajsb"; 
    // printf("%d\n", reverse_str(substring(s, 0, 2)));
    printf("%s\n", longestPalindrome(s));
    // char *test = substring(s, 0, 2);
    // printf("%s\n", test);
    // // printf("Median Sorted Arr: %f\n", findMedianSortedArrays(nums1, m, nums2, n));
    return 0;
}
