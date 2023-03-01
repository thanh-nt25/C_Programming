#ifndef __LLIST_H__
#define __LLIST_H__

#include "data_t.h"

typedef struct node_s {
    data_t data; // tao mot thuc te cua kieu cau truc data
    struct node_s *next;
}   node_t, *root_t; // tao con tro tro  den phan tu dau tien

root_t llPrint(root_t root);
node_t* CreateNewNode (const data_t data);
root_t llInit();

root_t llInsertHead(root_t root, const data_t data);
root_t llInsertStudent(root_t root, const data_t data);

root_t llDeleteAll(root_t root);

void showPtrData(data_t *data);
data_t* llFindStudent(root_t root, char *id);
root_t  llDeleteStudent(root_t root, char *id);
root_t llChangeGrade(root_t root, char *id, int new_grade);

#endif