#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "libs/bst_traversal.h"

#define NUM_LINE 20
#define MAX_WORDS 100


/* ============== File =================*/

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

/* ============ string =================*/

int word_count(char *sen){
    int count=0;
    for (int i=0; sen[i] != '\0'; ++i){
        if (sen[i] == ' ' || sen[i] == '\n') count++;
    }
    count++;
    return count;
}

char* to_single_lowcase(char *word){
    char *low_case = malloc(sizeof(word));
    for(int i=0; word[i] != '\0'; ++i ){
        low_case[i] = tolower(word[i]);
    }
    return low_case;
}

char **split_sentence(char *sentence) {
    char **words = malloc(MAX_WORDS * sizeof(char*));
    int i = 0;

    char *word = strtok(sentence, " ");
    while (word != NULL && i < MAX_WORDS) {
        words[i] = to_single_lowcase(word);
        i++;
        word = strtok(NULL, " ");
    }

    return words;
}

/* ============ Function to detect Menu ==========*/ 

void menuPrint(){
    printf("==========================\n");
    printf("1. Read file Data and move data to Binary Search Tree (arrange by End alphabet)\n");
    printf("2. Print Binary Search Tree sort by End alphabet\n");
    printf("3. Translate\n");
    printf("4. Exit\n");
    printf("5. Config data file\n");
    printf("==========================\n");
}

int check_choice(){
        int choice;
        do{
            printf("\nEnter the number of program (1 -> 4):\n");
            menuPrint();
            scanf("%d", &choice);
            fflush(stdin);
            if(choice < 1 || choice > 4) printf("Please enter the number from 1 to 4!\n");
        }while(choice < 1 || choice > 4);
        return choice;
}

void ReadFile(FILE *fp, char *file_open, tree_t *tree, data_t *trans, int *REAL_LINE){

    // truyen du lieu vao trans
    for(int i=0; i < *REAL_LINE; ++i){
        fscanf(fp,"%s", trans[i].Eng);
        fgetc(fp);
        fgets(trans[i].Viet, sizeof(trans[i].Viet), fp);
        reWrite(trans[i].Viet);
    }

    // truyen du lieu vao BST
    for(int i=0; i < *REAL_LINE; ++i){
        insertNode(trans[i], tree);
    }
}

// void write_to_BST(FILE *fr, char *file_BST, int *REAL_LINE){
//     if((fr = fopen(file_BST, "w+")) == NULL) printf("False\n");
//     for(int i=0; i < REAL_LINE; ++i){
//         reWrite(trans[i].Viet);
//         // fprintf(fr, "%d. Word \"%s\" means \"%s\"\n",i+1, trans[i].Eng, trans[i].Viet);
//     }
// }

void Print_BST(tree_t tree){
    printf("Dictionary from data file:\n\n");
    iter_inorder(tree);

}

void translate(tree_t tree, char sen[]){
            char sentence[MAX_WORDS];
            strcpy(sentence, sen);
            printf("Original Sentence: \"%s\"\n", sentence);
            int WORD_COUNT = word_count(sentence); 
            char **words = split_sentence(sentence);
            
            printf("All single words of sen:\n");
            for (int i = 0; i < WORD_COUNT; i++) {
                printf("%d. %s\n", i+1, to_single_lowcase(words[i]));
            }

            printf("Translate:\n");
            for (int i=0; i< WORD_COUNT; ++i){
                if (search(words[i], tree) == NULL){
                    printf("%s ", "\"Thieu tu\"");
                }
                else{
                    printf("%s ", search(words[i], tree)->data.Viet);
                }
            }

            free(words);
}

void config_file(FILE *fp){
    if ((fp = fopen("data.txt", "a+")) == NULL) printf("Cannot open\n");
    char *eng, *viet;
    printf("file 5\n");
    scanf("%s", eng);
    fflush(stdin);
    fgets(viet, sizeof(viet), stdin);
    fprintf(fp, "%s %s", eng, viet);
    fclose(fp);
}

/* ============ Main ==============*/ 

int main(void){
    FILE *fp = NULL;
    char *file_open = "data.txt";

    tree_t tree = NULL;
    word_t trans[NUM_LINE];
    int REAL_LINE = 0;
    if ((fp = fopen(file_open, "r")) == NULL) printf("Cannot open!\n");
    REAL_LINE = count_line(fp, file_open);


    int choice = 0;
    // chua co khoi tao va check ngay sau thi nen dung do-while truoc
    do{
        choice = check_choice();
        switch (choice)
        {
        case 1:
            printf("Real line is: %d\n", REAL_LINE);
            ReadFile(fp, file_open, &tree, trans, &REAL_LINE);
            break;
        case 2:
            Print_BST(tree);
            break;
        case 3:
            char sen[MAX_WORDS] = "I Go to SchOOl";
            // printf("Enter the sentence:\n");
            // // fflush(stdin);
            // // fgets(sen, sizeof(sen), stdin);
            // // scanf("%*[^\n]%*c", sen);
            // scanf("%*[^\n]%*c", sen);
            translate(tree, sen);
            break;
        case 4:
            break;
        case 5:
            config_file(fp);
            break;
        }
    }   while (choice != 4);
    // DFS print

    // BFS print

    // print data to output file and dislay
    // insertNode(trans[0], tree);
    // bien "tree" tuong duong voi 1 con tro "*pRoot"
    
    fclose(fp);
    return 0;
}