#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    FILE *fp = NULL;
    if ((fp = fopen("data.txt", "r")) == NULL) printf("Error while open file!\n");
    int test1, test2;
    char thanh[10], yen[10];
    fscanf(fp, "%s\t%d", thanh, &test1);
    printf("%s %d\n",thanh, test1);
    fscanf(fp, "%s\t%d", yen, &test2);
    printf("%s %d\n",yen, test2);
    return 0;
}