#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "libs/bst_traversal.h"

#define OPTIONS 5 // CHỈNH SỬA OPTIONS
#define NUM_LINE 20
#define MAX_WORDS 30

/* ===============================================================*/
/* ======================= Tiền xử lí ===========================*/

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

// thay thế \n trong con trỏ chuỗi = \0
void reWrite(char *word){
    int i=0;
    while(*(word+i) != '\n'){ // *(word+i) != '\r' 
        ++i;
    }
    *(word + i) = '\0';
}

// ko đếm được với con trỏ chuỗi
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

char* to_single_upcase(char *word){
    char *up_case = malloc(sizeof(word));
    for(int i=0; word[i] != '\0'; ++i ){
        up_case[i] = toupper(word[i]); 
    }
    return up_case;
}


// thay thế MAX_WORDS bằng số từ trong câu => trả lại con trỏ đến đầu chuỗi lưu trữ
// char *words = split_sentence(sen);
char **split_sentence(char *sentence) {
    // con tro luu dia chi cua con tro den chuoi can modi =)))
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

/* nhập chuỗi bằng hàm fgets
fflush(stdin);
fgets(str, sizeof(str), stdin);
str[strcspn(str, "\n")] = '\0';
*/

// scanf("%[^\n]%*c", sen);


/* ==================================================================*/
/* ================================= MENU ===========================*/ 
/* =================================================================*/

void menuPrint(){
    printf("==========================\n");
    printf("1. Read file Data and move data to Binary Search Tree (arrange by End alphabet)\n");
    printf("2. Print Binary Search Tree sort by End alphabet\n");
    printf("3. Translate\n");
    printf("4. Config data file\n");
    printf("5. Exit\n");
    printf("==========================\n");
}

int check_choice(){
        int choice;
        do{
            printf("\nEnter the number of program (1 -> %d):\n", OPTIONS);
            menuPrint();
            scanf("%d", &choice);
            fflush(stdin);
            if(choice < 1 || choice > OPTIONS) printf("Please enter the number from 1 to %d!\n", OPTIONS);
        }while(choice < 1 || choice > OPTIONS);
        return choice;
}

/* ====================================================================*/
/* ===================== Các hàm trong Menu ==========================*/ 
/* ==================================================================*/

void mot_ReadFile(FILE *fp, char *file_open, tree_t *tree, data_t *trans, int *REAL_LINE){
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
    printf("Real line is: %d\n", REAL_LINE);
}

void hai_Print_BST(tree_t tree){
    printf("Dictionary from data file:\n\n");
    iter_inorder(tree);

}

void ba_translate(tree_t tree, char sen[]){
            printf("Original Sentence: \"%s\"\n", sen);
            int WORD_COUNT = word_count(sen);
            printf("Number of word is: %d\n", WORD_COUNT);
            
            char **words = split_sentence(sen);
            
            printf("All single words of sen:\n");
            for (int i = 0; i < WORD_COUNT; i++) {
                printf("%d. \"%s\"\n", i+1, to_single_lowcase(words[i]));
            }

            printf("Translate:\n\"");
            for (int i=0; i< WORD_COUNT; ++i){
                // printf("%s", tree->data.Viet);
                printf("%s ", search(to_single_lowcase(words[i]), tree)->data.Viet);
            }
            printf("\"");
            free(words);
}

void bon_config_file(){
    printf("option 5\n");
}


/* ===============================================================*/
/* ============================ Main =============================*/ 
/* ===============================================================*/

// int main(int argc, char *argv[])
int main(void){
    FILE *fp = NULL;
    char *file_open = "data.txt"; // CHINH SUA TEN FILE DATA

    tree_t tree = NULL;
    word_t trans[NUM_LINE]; // CHỈNH THEO TÊN (LƯU TRỮ DATA)
    
    if ((fp = fopen(file_open, "r")) == NULL) printf("Cannot open!\n");
    
    int REAL_LINE = 0;
    REAL_LINE = count_line(fp, file_open);


    int choice = 0;
    do{
        choice = check_choice();
        switch (choice)
        {
        case 1:
            mot_ReadFile(fp, file_open, &tree, trans, &REAL_LINE);
            break;
        case 2:
            hai_Print_BST(tree);
            break;
        case 3:
            char sen[MAX_WORDS] = "I go to school";
            ba_translate(tree, sen);
            break;
        case 4:
            bon_config_file();
            break;
        case 5:
            break;
        }
    }   while (choice != OPTIONS);

    // GIAI PHONG BO NHO
    fclose(fp);
    return 0;
}