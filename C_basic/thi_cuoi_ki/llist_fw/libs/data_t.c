#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "data_t.h"

void ShowData (data_t data)
{
    printf("%s - %s - %d\n", data.id, data.name, data.grade);
}

data_t convert(char *id, char *name, int grade){
    data_t tmp;
    tmp.grade = grade;
    strcpy(tmp.id, id);
    strcpy(tmp.name, name);
    return tmp;
}