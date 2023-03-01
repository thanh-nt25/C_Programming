#ifndef __DATA_H__
#define __DATA_H__

typedef struct {
    char id[16];
    char name[40];
    int grade;
}   student;

typedef student data_t;

void ShowData (const data_t data);
data_t convert(char *id, char *name, int grade);

#endif