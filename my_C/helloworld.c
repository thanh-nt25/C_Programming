#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 30

int word_count(char *sen){
    int count=0;
    for (int i=0; sen[i] != '\0'; ++i){
        if (sen[i] == ' ' || sen[i] == '\n') count++;
    }
    count++;
    return count;
}


// tra lai mot chuoi khac da duoc phan tach tu chuoi ban dau
void split_sentence(char *str, int NbrWords){
    char *words = str; // de ko tac dong truc tiep vao chuoi ban dau
    char *p = strtok(words, " ");
    printf("%s\n", p);
    int i = 0;
    while(p != NULL && i < NbrWords){
        p = strtok(NULL, " ");
        if(p != NULL) printf("%s\n", p);
        ++i;
    }
}

int main(void){
    // char *str = malloc(sizeof(char) * MAX_WORDS);
    char *str;
    // char str[20];
    scanf("%[^\n]%*c", str);    
    // fflush(stdin);
    // fgets(str, sizeof(str), stdin);
    // str[strcspn(str, "\n")] = '\0';

    int NbrWords = word_count(str);
    printf("Number of word is: %d\n", NbrWords);

    // char *p = strtok(str, " ");
    // printf("%s\n", p);
    // while (p != NULL){
    //     p = strtok(NULL, " ");
    //     if(p != NULL) printf("%s\n", p);
    // }
    split_sentence(str, NbrWords);
    return 0;
}