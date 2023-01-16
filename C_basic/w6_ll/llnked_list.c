#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char name[20];
    int id;
}data_t;

typedef struct node_s{
    data_t data;
    struct node_s *next;
}node_t, *root_t;

root_t llInit() { return NULL; }

void showdata(data_t data){
    printf("%s - %d\n", data.name, data.id);
}

root_t llprint(root_t root){
    for(node_t *q = root; q != NULL; q = q->next) showdata(q -> data);
    printf("\n");
    return root;
}

node_t *createnode(data_t data){
    node_t *newnode = (node_t *)malloc(sizeof(node_t));
    if (newnode == NULL) return NULL;

    newnode -> next = NULL;
    newnode -> data = data;
    return newnode;
}

/*============= insert ====================*/

root_t llInsertTail(root_t root, const data_t data){
    node_t *newnode = createnode(data);
    if (root == NULL) return newnode;

    node_t *q;
    for (q = root; q -> next != NULL; q = q->next) ;
    q->next = newnode;
    return root;
}

root_t llInsertHead(root_t root, const data_t data){
    node_t *newnode = (node_t *)malloc(sizeof(node_t));
    newnode -> next = root;
    newnode -> data = data;
    if (root == NULL) return newnode;
    return newnode;
}

root_t llInsertStudent(root_t root, const data_t data){
    node_t *curr_std, *prev_std = NULL;

    node_t *newnode = (node_t *)malloc(sizeof(node_t));
    if(root == NULL) return newnode;
    newnode -> data = data;
    newnode -> next = NULL;


    if ((newnode ->data).id > (root -> data).id)
        {
            newnode -> next = root;
            return newnode;
        }
    else
        {
            curr_std = root;
            while (curr_std != NULL && ((newnode ->data).id < (curr_std -> data).id))
            {
                prev_std = curr_std;
                curr_std = curr_std -> next;
            }
            prev_std -> next = newnode;
            newnode -> next = curr_std;
            return root;
        }
}

/* ============== tools ========================*/ 


/*========= main ======================*/

int main(void)
{
    data_t student[] = {{"sv1", 1},
                    {"sv2", 3},
                    {"sv3", 5},
                    {"sv4", 7},
                    {"sv5", 9},
                    {"sv6", 11}}; 
    data_t student7 = {"sv7",13};
    data_t student8 = {"sv8", 8};
    root_t lst = llInit();
    for (int i=0; i < sizeof(student)/sizeof(student[0]); ++i){
        // lst = llInsertTail(lst, student[i]);
        lst = llInsertHead(lst, student[i]);
    }

    llprint(lst);

    lst = llInsertHead(lst, student7);
    llprint(lst);

    lst = llInsertHead(lst, student8);
    llprint(lst);

    return 0;
}