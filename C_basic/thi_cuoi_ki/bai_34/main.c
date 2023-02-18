#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include "bst_traversal.h"

#define NUM_LINE 20

/* ============ Adapt ==============*/ 

typedef struct{
    char Eng[21];
    char Viet[21];
}   word_t;
typedef word_t data_t;

typedef struct node_s{
    data_t data;
    struct node_t *right;
    struct node_t *left;
}   node_t;

typedef node_t *tree_t;

/* ============ Data ============= */

/* ============ BST ============== */ 

void insertNode(data_t x, tree_t *pRoot){
  if (*pRoot == NULL) {
    /* Create a new node for key x */
    *pRoot = (node_t *)malloc(sizeof(node_t));
    (*pRoot)->data = x;  // <===
    (*pRoot)->left = NULL;
    (*pRoot)->right = NULL;
  } else if (lt(x.Eng, &((*pRoot)->data.Eng)))  // <===
    insertNode(x, &((*pRoot)->left));
  else if (gt(x.Eng, &((*pRoot)->data.Eng)))  // <===
    insertNode(x, &((*pRoot)->right));    
}

/* ============ File ============== */ 


int count_line(FILE *fp, char *file_name){
    int count = 0;
    char ch;
    if ((fp = fopen(file_name, "r+")) == NULL) return -1;
    do{
        ch = fgetc(fp);
        if(ch == '\n') count++;
    }   while(ch != EOF);
    return count;
}

void reWrite(char *word){
    int i=0;
    while(*(word+i) != '\n'){
        ++i;
    }
    *(word + i) = '\0';
}

/* ============ Main ==============*/ 

word_t trans[NUM_LINE];

int main(void){
    FILE *fp = NULL;
    FILE *fr = NULL;
    char *file_open = "data.txt";
    char *file_write = "translate.txt";

    tree_t tree = NULL;

    if ((fp = fopen(file_open, "r")) == NULL) printf("Cannot open!\n");
    int REAL_LINE = count_line(fp, file_open);

    for(int i=0; i < REAL_LINE; ++i){
        fscanf(fp,"%s", trans[i].Eng);
        fgetc(fp);
        fgets(trans[i].Viet, sizeof(trans[i].Viet), fp);
    }
        if((fr = fopen(file_write, "w+")) == NULL) printf("False\n");
    for(int i=0; i < REAL_LINE; ++i){
        reWrite(trans[i].Viet);
        fprintf(fr, "%d. Tu \"%s\" co nghia la \"%s\"\n",i+1, trans[i].Eng, trans[i].Viet);
    }

    fclose(fp);
    fclose(fr);
    return 0;
}