#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHAR 20
#define UNDEFINE '\0'
#define TABLE_SIZE 13

enum {FALSE, TRUE};
/* ========================= Hash Table =================== */
typedef struct {
    char key[MAX_CHAR];
    int value;
}   element;

int transform(char *key){
    int hk=0;
    for (int i=0; key[i] != '\0'; ++i){
        hk+=*(key+i);
    }
    return hk;
}

int hash(char *key){
    return transform(key) % TABLE_SIZE; 
}

void init_ht(element ht[]){ ht[0].key[0] = UNDEFINE; }

int insertht(element ht[], element e){
    if (ht[0].key[0] != UNDEFINE)
        return -1;
    else if(ht[e.value].key[0] != '\0'){
        return FALSE;
    }
    else{
        strcpy(ht[e.value].key, e.key);
        ht[e.value].value = e.value;
        return TRUE;
    }
}

void traversal(element ht[]){
    for(int i=0; i < TABLE_SIZE; ++i){
        if (ht[i].key[0] != '\0' )
            printf("%d, %s\n", ht[i].value, ht[i].key);
    }
}

/* ================== Main ==========================*/
element hash_table[TABLE_SIZE];

int main(void){
    char *keys[] = {"Lisa Smith","Taylor Swift", "Leo Messi", "Sam Smith", "Neymar Jr."};

    printf("Infor of keys is:\n");
    for(int i=0; i < sizeof(keys)/sizeof(keys[0]) ; ++i){
        printf("%s = %d\n",keys[i], hash(keys[i]));
    }
    printf("\n");

    init_ht(hash_table);
    for(int i=0; i<sizeof(keys)/sizeof(keys[0]); i++){
        element e;
        strcpy(e.key, keys[i]);
        e.value = hash(keys[i]);
        insertht(hash_table, e);
    };
    printf("Hash Table is:\n");
    traversal(hash_table);
    printf("\n");
    // printf("%s", keys[0]);
    // printf("%c", *(keys[0]+1));

    return 0;
}
