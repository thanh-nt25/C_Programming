#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libs/bst_traversal.h"

#define Days 10

// typedef struct cp_t{
//     char maCP[4];
//     float mocua;
//     float dongcua;
// }   cp_t;


int main(void){
    tree_t tree = NULL;
    FILE *fp = NULL;
    char file_data[] = "data.txt";
    if ((fp = fopen(file_data, "r")) == NULL) printf("Error\n");
 
    int N; //so co phieu
    fscanf(fp, "%d", &N); // doc lay key
    int NumSt = Days * N;

    cp_t stock[NumSt];
    for (int i=0; i < (Days*N); ++i){
            fscanf(fp, "%s\t%g\t%g", stock[i].ma, &stock[i].mocua, &stock[i].dongcua);
    }

    int avg_mocua = 0, avg_dongcua = 0;

    for (int i=0; i < NumSt; ++i){
        insertNode(stock[i], &tree);
    }
    printf("Infor of Stock:\n");
    // prettyPrint(tree);
    iter_inorder(tree);
    // for(int i=0; i < NumSt; ++i){
    //     showData(stock[i]);
    // }


    fclose(fp);
    return 0;
}