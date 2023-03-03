#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{

int id; // id cua nut

struct Node* next; // con tro tro den nut tiep theo

}Node;

// Hỏi hàm proc sau đây thực hiện công việc gì?

Node *createNode(int id){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode -> id = id;
    newNode -> next = NULL;
    return newNode;
}

void insertTail(Node *root, int id){
    Node *newnode = createNode(id);
    if ( root == NULL) {
        root = newnode;
        return;
    }
    Node *q = root;
    for (int i=0; q->next != NULL; ++i ){
        q = q->next;
    }
    q -> next = newnode;
}

Node* proc(Node* f, int v){

    if(f==NULL) return NULL;

    if(f->id == v){

        Node* tm = f; f = f->next; free(tm); return f;

    }

    f->next = proc(f->next,v);

    return f;

}

int main(void){
    Node* root = NULL;
    insertTail(root, 20);
    printf("%d\n", root->id);
    return 0;
}