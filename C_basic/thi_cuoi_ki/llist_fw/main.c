#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

#include "libs/llist.h"

#define OPTIONS 6
#define NUM_STD 1000 // SỐ TRƯỜNG THỰC THỂ DỮ LIỆU

#define MAX_WORDS 20

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
    printf("1. \n");
    printf("2. \n");
    printf("3. \n");
    printf("4. \n");
    printf("5. \n");
    printf("6. Exit\n");
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

void mot_(){
    printf("1st function\n");
    // chuyển dữ liệu => data structure => BST
    // YOUR CODE

}

void hai_(){
    printf("2nd function\n");
    // YOUR CODE
}

void ba_(){
    printf("3rd function\n");
    // YOUR CODE
}

void bon_(){
    printf("4st function\n");
    // YOUR CODE
}

void nam_(){
    printf("5st function\n");
    // YOUR CODE
}


/*================ Main function ====================*/ 

int main (void)
{
    FILE *fp = NULL;
    char *file_open = "data.txt";

    if ((fp = fopen(file_open, "r")) == NULL) printf("Cannot open!\n");

    root_t lst = llInit();

    int choice = 0;
    do{
        choice = check_choice();
        switch (choice)
        {
        case 1:
            mot_();
            break;
        case 2:
            hai_();
            break;
        case 3:
            ba_();
            break;
        case 4:
            bon_();
            break;
        case 5:
            nam_();
            break;
        case 6:
            break;
        }
    }   while (choice != OPTIONS);

    for(int i=0; i<sizeof(student)/sizeof(student[0]); i++)
        lst = llInsertHead(lst, student[i]);
    llPrint(lst);


    // giai phong bo nho khi ket thuc chuong trinh
    lst = llDeleteAll(lst);

    fclose(fp);
    return 0;
}