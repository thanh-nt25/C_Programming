#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int id;
    char name[30];
}data_t;

typedef struct std_link{
    data_t data;
    struct std_link *prev;
    struct std_link *next;
}std_link;

struct std_link *head;
struct std_link *tail;

/*============================ Adapt =================================*/

std_link *createNode(const data_t data){
    std_link *newnode = (std_link *)malloc(sizeof(std_link));
    newnode -> data = data;
    newnode -> prev = NULL;
    newnode -> next = NULL;
    return newnode;
}

void showdata(data_t data){
    printf("%s - %d\n", data.name, data.id);
}

void dlprint(std_link *head){
    std_link *q=NULL;
    for(q = head; q != NULL; q = q->next) showdata(q->data);
    printf("\n");
}


void dlInit(){
    head = NULL;
    tail = NULL;
}

data_t convert(char name[], int id){
    data_t data;
    data.id = id;
    strcpy(data.name,name);
    return data;
}

/*=========================== Insert =============================*/

void dlInsertHead(const data_t data){
    std_link *newnode = createNode(data);
    if(head == NULL && tail == NULL) {
        head = newnode;
        tail = newnode;
        return; 
    // ko co return, gan head = new va van thuc hien cac lenh sau :))
    }
    head -> prev = newnode;
    newnode -> next = head;
    head = newnode;
}


void dlInsertTail(const data_t data){
    std_link *newnode = createNode(data);
    if(head == NULL && tail == NULL) {
        head = newnode;
        tail = newnode;
        return;
    }
    tail -> next = newnode;
    newnode -> prev = tail;
    tail = newnode;
}

void InsertStudent(){
    int std_num;
    printf("Enter the number of std:\n");
    scanf("%d", &std_num);
    char name[30]; int id;
    if(std_num == 1){
        printf("Enter the name of std: ");
        scanf("%s", name);
        printf("Enter the id: ");
        scanf("%d",&id);
        data_t data = convert(name,id);
        std_link *newnode = createNode(data);
        if (head == NULL){
            head = newnode;
            tail = newnode;
            return;
        }
        if(newnode->data.id < head->data.id){
            head -> prev = newnode;
            newnode -> next = head;
            head = newnode;
            return;
        }
        std_link *q=head;
        while((q->next != NULL) && (newnode->data.id < q->data.id)){
            printf("%d\n",q->data.id);
            q=q->next;
            printf("Tail is: %d\n",tail->data.id);
        }
        // if (tail->next == NULL) printf("true\n");
        if(q->next == NULL){
            tail -> next = newnode;
            newnode -> prev = tail;
            tail = newnode;
            return;
        }
        newnode->next=q->next;
        newnode->prev=q;
        q->next=newnode;
        newnode->next->prev=q;
        return;
    }
    else {
        char name[3]; int id;
        name[0]='s'; name[1]='v';
        int id_begin;
        printf("The id of std begin from:\n");
        scanf("%d", &id_begin);
    }
}

/*======================== Delete ============================*/

int dlempty(){
    return (head = NULL) && (tail = NULL);
}

void dlDeleteStudent(std_link *head, int id){
    
}

/*======================== tools ==============================*/

void print_menu(){
        printf("=======================================\n");
        printf("=======================================\n");
        printf("                  MENU                 \n");
        printf("1. Enter the inf of student (from head)\n");
        printf("2. Enter the inf of student (from tail)\n");
        printf("3. Printf student list\n");
        printf("4. Delete list\n");
        printf("5. Insert Student\n");
        printf("0. Exit!\n");
        printf("---------------------------------------\n");
}

int main(void){
    dlInit();
    int req;
    char name[30]; int id;
    while(1){
        print_menu();
        printf("Enter the number command that you want:\n");
        scanf("%d",&req);
        switch(req){
            case 1: printf("Enter the name of std: ");
                    scanf("%s", name);
                    printf("Enter the id: ");
                    scanf("%d",&id);
                    dlInsertHead(convert(name,id));
                    break;
            case 2: printf("Enter the name of std: ");
                    scanf("%s", name);
                    printf("Enter the id: ");
                    scanf("%d",&id);
                    dlInsertTail(convert(name,id));
                    break;
            case 3: printf("Linked list is:\n"); dlprint(head);
                    break;
            case 4: dlempty();
                    break;
            case 5: InsertStudent();
                    break;
            case 0: return 1;
                    break;
        }
    }
    return 0;
}