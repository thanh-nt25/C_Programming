/*
  Ho va ten: Nguyen Tuan Thanh
  MSSV: 20210800
  Ngay hoan thanh: 24-11-2022
  Ten chuong trinh: Tinh tong 2 so dua tren cau truc du lieu stack
*/ 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
enum {EXIT_STACK_OVERFLOW = 1, EXIT_STACK_UNDERFLOW, EXIT_STACK_EMPTY};

typedef int data_t;

typedef struct node_s
{
    data_t data;
    struct node_s *next;
}node_t, *root_t;

typedef root_t stack_t;


/*====================== function ======================*/

void showData(data_t data);
data_t convert(int num);

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
    printf("%d", data);
}

data_t convert(int num) {
    return num;
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
    // truyen du lieu cua 2 so vao stack
    stack_t s1 = llInit();

    s1 = push(s1,8);
    s1 = push(s1,7);
    s1 = push(s1,3);
    s1 = push(s1,2);

    stack_t s2 = llInit();
    s2 = push(s2,5);
    s2 = push(s2,6);
    s2 = push(s2,2);
    s2 = push(s2,9);

    stack_t sum_t = llInit();

    printf("Sum of 8732 and 5629 is:\n");
    // Pop data from Stack and display to screen
    // top return data
    int sum=0,rem=0, p=0;

    // ham tinh tong va truyen du lieu vao stack sum
    while((isEmpty(s1) != 1) && (isEmpty(s2) != 1)){
      sum = top(s1) + top(s2) + rem;
      rem = sum /10;
      p = sum % 10;
      sum_t = push(sum_t,p);
      s1 = pop(s1);
      s2 = pop(s2);
    }
    sum_t = push(sum_t,rem);

    // in stack sum
    while (!isEmpty(sum_t)) {
        showData(top(sum_t));
        sum_t = pop(sum_t);
    }
    printf("\n");

    return 0;
}