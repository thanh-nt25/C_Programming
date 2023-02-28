#include <stdio.h>

int sequential_search(char *items, int count, char key){
    register int t;
    for(t = 0; t < count; t++){
        if(items[t] == key) return t;
    }
    return -1;
}

int main(void){
    char *str = "asdf";
    int index = sequential_search(str,4,'s');
    printf("%d \n", index);
    return 0;
}