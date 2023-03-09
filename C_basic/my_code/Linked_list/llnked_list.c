#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// typedef struct{
    // char name[20];
    // int id;
// }data_t;

typedef int data_t;
typedef struct node_s{
    data_t data;
    struct node_s *next;
}node_t, *root_t;

root_t llInit() { return NULL; }

void showdata(data_t data){
    printf("%d ", data);
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

    node_t *q; // q3
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

root_t AddTwoNumbers(root_t l3, root_t l1, root_t l2){
    // root_t l3 = llInit();
    int rem = 0, sum = 0;

    root_t q3 = l3;
    root_t q1 = l1; 
    root_t q2 = l2;
    
    int count = 0;
    int num1, num2;
    while(!((q1 == NULL) && (q2 == NULL))){
        num1 = num2 = 0;
        if (q1 != NULL) num1 = q1 -> data;
        if (q2 != NULL) num2 = q2 -> data;
        sum = num1 + num2 +rem; // func to count sum
        rem = 0;
        if (sum >= 10){
            rem = sum / 10;
            sum = sum % 10;
        }
        l3 = llInsertTail(l3, sum); // reverse in problem
        sum = 0;
        if(q2 != NULL) q2 = q2 -> next;
        if(q1 != NULL) q1 = q1 -> next;
        if ((q1 == NULL) && (q2 == NULL) && rem != 0) l3 = llInsertTail(l3, rem);
        ++count;
    }
    return l3;
}

// root_t llInsertStudent(root_t root, const data_t data){ // co sap xep
//     node_t *curr_std, *prev_std = NULL;

//     node_t *newnode = (node_t *)malloc(sizeof(node_t));
//     if(root == NULL) return newnode;
//     newnode -> data = data;
//     newnode -> next = NULL;


//     if ((newnode ->data).id > (root -> data).id)
//         {
//             newnode -> next = root;
//             return newnode;
//         }
//     else
//         {
//             curr_std = root;
//             while (curr_std != NULL && ((newnode ->data).id < (curr_std -> data).id))
//             {
//                 prev_std = curr_std;
//                 curr_std = curr_std -> next;
//             }
//             prev_std -> next = newnode;
//             newnode -> next = curr_std;
//             return root;
//         }
// }

/* ============== tools ========================*/ 


/*========= main ======================*/

int main(void)
{
    // data_t student[] = {{"sv1", 1},
    //                 {"sv2", 3},
    //                 {"sv3", 5},
    //                 {"sv4", 7},
    //                 {"sv5", 9},
    //                 {"sv6", 11}}; 
    // data_t student7 = {"sv7",13};
    // data_t student8 = {"sv8", 8};
    root_t l1 = llInit();
    root_t l2 = llInit();
    root_t l3 = llInit();
    // l1 = llInsertHead(l1, 3);
    // l1 = llInsertHead(l1, 4);
    // l1 = llInsertHead(l1, 2);
    // l2 = llInsertHead(l2, 4);
    // l2 = llInsertHead(l2, 6);
    // l2 = llInsertHead(l2, 5);
    
    // l1 = llInsertHead(l1, 0);
    // l2 = llInsertHead(l2, 0);

    for (int i=0; i<7; ++i){
        l1 = llInsertHead(l1, 9);
    }
    for (int i=0; i<4; ++i){
        l2 = llInsertHead(l2, 9);
    }
    // printf("%d\n", !(1&&1));   // = 0 (false)  
    // printf("%d\n", !(0&&0));    // = 1 
    // printf("%d\n", !(1 && 0)); // = 1 
    while ((1 && 0)){
        printf("while test\n");
    }

    printf("l1: "); llprint(l1);
    printf("l2: "); llprint(l2);
    l3 = AddTwoNumbers(l3, l1 , l2);
    printf("l3: "); llprint(l3); 
    // for (int i=0; i < sizeof(student)/sizeof(student[0]); ++i){
    //     // lst = llInsertTail(lst, student[i]);
    //     lst = llInsertHead(lst, student[i]);
    // }

    // llprint(lst);

    // lst = llInsertHead(lst, student7);
    // llprint(lst);

    // lst = llInsertHead(lst, student8);
    // llprint(lst);

    return 0;
}