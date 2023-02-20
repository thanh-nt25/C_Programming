#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100

char **split_sentence(char *sentence) {
    char **words = malloc(MAX_WORDS * sizeof(char*));
    int i = 0;

    char *word = strtok(sentence, " ");
    while (word != NULL && i < MAX_WORDS) {
        words[i] = word;
        i++;
        word = strtok(NULL, " ");
    }

    return words;
}

int main() {
    // char *sen = "This is a sentence";
    // char sentence[MAX_WORDS];
    // for (int i=0; sen[i] != '\0'; ++i){
    //     sentence[i] = sen[i];
    // }
    // char **words = split_sentence(sentence);

    // for (int i = 0; i < 2; i++) {
    //     printf("%s\n", words[i]);
    // }

    // free(words);
    char sen[10];
    scanf("%[^\n]%*c", sen);
    printf("%s", sen);
    return 0;
}
