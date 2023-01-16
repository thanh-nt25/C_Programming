/*
  Ho va ten: Nguyen Tuan Thanh
  MSSV: 20210800
  Ma lop: 135307
  Ngay hoan thanh: 18-11-2022
  Ten chuong trinh: Reverse a String used Stack (Implementation using linked list)
  Muc tieu:
    + Nhap mot chuoi ki tu
    + Dao nguoc chuoi bang Stack (using linked list)
    + Khong su dung thu vien vi chuong trinh ngan va ham can su dung it
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
enum {EXIT_STACK_OVERFLOW = 1, EXIT_STACK_UNDERFLOW, EXIT_STACK_EMPTY, MAX_LEN = 100};

typedef char data_t;
typedef struct node_s
{
    data_t data;
    struct node_s *next;
}node_t, *root_t;

typedef root_t stack_t;


/*====================== function ======================*/

void showData(data_t data);
data_t convert(char c);

stack_t stackInit();

int isEmpty(stack_t stack);
int isFull(stack_t stack);

root_t push(stack_t stack, const data_t data);
stack_t pop(stack_t stack);
stack_t popData(stack_t stack, data_t *pData);

data_t top(stack_t stack);

root_t llInit();

root_t llInsertHead(root_t root, const data_t data);


root_t llDeleteHead(root_t root);

/*==================== adapt ==========================*/

/************ data **************/
void showData(data_t data) {
    printf("%c", data);
}

data_t convert(char c) {
    return c;
}
/************ stack **************/

stack_t stackInit() { return llInit(); }

int isEmpty(stack_t s) { return s == NULL; }

int isFull(stack_t s) { return 0; }

stack_t push(stack_t stack, const data_t data) {
  return llInsertHead(stack, data);
 }

stack_t pop(stack_t stack) {
  return llDeleteHead(stack);
}

stack_t popData(stack_t stack, data_t *pData) {
  *pData = top(stack);
  return pop(stack);
}

data_t top(stack_t stack) {
  if (isEmpty(stack)) {
    printf("ERROR: Empty Stack!!!\n");
    exit(EXIT_STACK_EMPTY);
  }
  data_t data = stack->data;
  return data;
}

/************ llist **************/

node_t* createNewNode(const data_t data) {
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  if (newNode == NULL) return NULL;

  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}
// Traversing a list and show
// root_t llPrint(root_t root) {
root_t llInit() { return NULL; }

root_t llInsertHead(root_t root, const data_t data) {
  node_t* pNewNode = createNewNode(data);
  pNewNode->next = root;
  return (root_t)pNewNode;
}

root_t llDeleteHead(root_t root) {
  if (root == NULL) return NULL;

  node_t* p = root->next;
  free(root);
  return (root_t)p;
}

/*====================== main =======================*/

int main(void)
{
    stack_t s = llInit();

    char word[MAX_LEN];
    printf("Enter the string you want to reverse (not include backspace):\n");
    scanf("%s", word);

    // truyen du lieu cua string vao stack
    data_t t = (data_t)word[0];
    int i=0;
    while (t != '\0' ){
        s = push(s, t);
        ++i;
        t = (data_t)word[i];
    }
    
    // Pop data from Stack and display to screen

    printf("String after reversed:\n");
    while (!isEmpty(s)) {
        showData(top(s));
        s = pop(s);
    }
    printf("\n");
    return 0;
}