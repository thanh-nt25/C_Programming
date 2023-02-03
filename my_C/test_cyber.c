#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func(char arg1[], int arg2){
    int loc1;
    char buff1[15];
    char buff2[10];
    printf("buff2 before: \n");
    printf("%s\n", buff2);
    printf("loc1 before: \n");
    printf("%d \n", loc1);

    for(int alloc = 0; alloc < 20; ++alloc){
        buff1[alloc] = 'a';
    }
    printf("size of loc1 & buff2 before: %ld & %ld \n", sizeof(loc1), sizeof(buff2));
    printf("Sizeof buff1 func: %ld \n", sizeof(buff1));
    // write my code
    printf("buff1 after: \n");
    printf("%s\n", buff1);
    printf("loc1 after: \n");
    printf("%d \n", loc1);
}

int main(void){
    char arg1[]="abcd";
    int arg2 = 2;

    printf("Size of arg1: %ld\n", sizeof(arg1));
    printf("Size of arg2: %ld\n", sizeof(arg2));
    func(arg1, arg2);

}