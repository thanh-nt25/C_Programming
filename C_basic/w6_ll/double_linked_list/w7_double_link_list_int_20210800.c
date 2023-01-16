/*
    Ho va ten: Nguyen Tuan Thanh
    MSSV: 20210800
    Ten chuong trinh: Chương trình làm việc với kiểu dữ liệu danh sách liên kết kép (double link list)
    Muc tieu: Co cac ham sau: 
        + thêm phần tử đầu danh sách: root_t dlInsertHead(root_t pHead, data_t data);
        + thêm phần tử cuối danh sách: root_t dlInsertTail(root_t root, data_t data);
        + thêm phần tử sau một phần tử trỏ bởi p trong danh sách: root_t dlInsertAfter(root_t root, node_t *pAElem, data_t data);
        + thêm phần tử trước một phần tử trỏ bởi p trong danh sách: root_t dlInsertBefore(root_t root, node_t *pAElem, data_t data);
        + xóa phần tử đầu danh sách: root_t llDeleteHead(root_t root);
        + xóa phần tử cuối danh sách: root_t llDeleteTail(root_t root);
        + xóa phần tử trỏ bởi con trỏ pAElem: root_t llDelete(root_t root, node_t* pAElem);
        + xóa toàn bộ danh sách: root_t llDeleteAll(root_t root);
        + hiển thị toàn bộ danh sách
    Ngay hoan thanh: 24/11/22
*/ 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int id;
} data_t;

typedef struct node_s{
    data_t data;
    struct node_s *next, *prev;
}   node_t, *root_t;

/*============================= Must Adapt ===========================*/ 

void showData(const data_t data){
    printf("%d\t", data.id);
}

root_t dlInit() {return NULL;}

// Ham in danh sach
root_t dlprint(root_t root){
    for (node_t* q = root; q != NULL; q = q->next) showData(q -> data);
    printf("\n");
    return root;
}

node_t *createnewnode(const data_t data){
    node_t *newnode = (node_t *)malloc(sizeof(node_t));
    if(newnode == NULL) return NULL;
    newnode -> data = data;
    newnode -> next = NULL;
    newnode -> prev = NULL;
    return newnode;
}

node_t *dlseek(root_t root, int index){
    node_t *q;
    for(q = root; index > 1 && (q != NULL); index--) q =  q->next;
    return q;
}

/*============ insert ===================*/

// Ham them phan tu dau danh sach
root_t dlInsertHead(root_t root, const data_t data){
    node_t *newnode = createnewnode(data);
    if(root == NULL) return newnode;

    newnode -> next = root;
    root->prev = newnode;
    return newnode;
}

// Ham them phan tu cuoi danh sach
root_t dlInsertTail(root_t root, const data_t data){
    node_t *newnode = createnewnode(data);
    if (root == NULL) return (root_t)newnode;

    newnode -> next = NULL;
    node_t *q = NULL;
    for(q = root; q ->next != NULL; q = q->next);

    q -> next = newnode;
    newnode ->prev = q;
    return root;
}

// Ham them phan tu sau phan tu tro boi con tro pAElem
root_t dlInsertAfter(root_t root, node_t *pAElem, data_t data){
    if (pAElem == NULL) return root;
    node_t* pNewNode = createnewnode(data);
    pNewNode->next = pAElem->next;
    pAElem->next = pNewNode;
    pAElem->next->prev=pNewNode;
    pNewNode->prev=pAElem;
    return root;
}

// Ham them phan tu truoc phan tu tro boi con tro pAElem
root_t dlInsertBefore(root_t root, node_t *pAElem, data_t data){
    if (pAElem == NULL) return root;
    node_t *pNewNode = createnewnode(data);
    pAElem->prev->next = pNewNode;
    pNewNode ->next = pAElem;
    pNewNode->prev = pAElem->prev;
    pAElem->prev = pNewNode;

    return root;
}

/*============= delete ================*/ 

// Ham xoa phan tu dau tien
root_t dlDeleteHead(root_t root){
    if(root == NULL) return NULL;

    node_t *p = root->next;
    free(root);
    return p;
}

// Ham xoa phan tu cuoi cung
root_t dlDeleteTail(root_t root) {
  if (root == NULL) return NULL;
  if (root->next == NULL) {
    free(root);
    return NULL;
  }
  node_t* p;
  // Find previous node of Tail
  for (p = root; p->next->next != NULL; p = p->next)
    ;
  free(p->next);
  p->next = NULL;
  return (root_t)root;
}

// Ham xoa phan tu sau phan tu tro boi con tro pA
root_t dlDeleteAfter(root_t root, node_t* pA) {
    if ((pA == NULL) || (pA->next == NULL)) return root;

    node_t* pToDelElem = pA->next;
    pA->next = pA->next->next;
    pA->next->next->prev = pA;
    free(pToDelElem);
    return root;
}

// Ham xoa phan tu truoc phan tu tro boi con tro pA
root_t dlDeleteBefore(root_t root, node_t* pA) {
    if ((pA == NULL) || (pA->prev == NULL)) return root;

    node_t* pToDelElemt = pA->prev;
    pA->prev->prev->next = pA;
    pA->prev = pA->prev->prev;
    free(pToDelElemt);
    return root;
}

// Ham xoa phan tu tro boi con tro pAElem
root_t dlDeleteNode(root_t root, node_t* pAElem){
    if(pAElem == NULL) return root;

    pAElem->prev->next=pAElem->next;
    pAElem->next->prev=pAElem->prev;
    free(pAElem);
    return root;

}

// Ham xoa toan bo danh sach
root_t dlDeleteAll(root_t root) {
  node_t* p = NULL;
  for (; root != NULL; root = p) {
    p = root->next;
    free(root);
  }
  return NULL;
}

/*==================== tools =================*/

data_t convert(int i){
    data_t data = {i};
    return data;
}

/*======================== main =====================*/ 

int main(void){
    data_t num[7];

    root_t lst = dlInit();
    for(int i=1; i <= sizeof(num)/sizeof(num[0]); ++i){
        lst = dlInsertHead(lst, convert(i));
        // lst = dlInsertTail(lst, convert(i));
    }
    printf("Danh sach lien ket voi so nguyen:\n");
    dlprint(lst);

    printf("\n-------------- Insert ----------------\n\n");
    node_t *p = dlseek(lst, 2);
    printf("Di chuyen con tro p den thu nut 2 (6)\n");
    printf("Them phan tu (9) sau p:\n");
    lst = dlInsertAfter(lst, p, convert(9));
    dlprint(lst);
    printf("Them phan tu (8) truoc p:\n");
    lst = dlInsertBefore(lst, p, convert(8));
    dlprint(lst);

    printf("\n-------------- Delete ----------------\n\n");
    printf("Xoa phan tu dau danh sach (7):\n");
    lst = dlDeleteHead(lst);
    dlprint(lst);
    
    printf("Xoa phan tu cuoi danh sach (1):\n");
    lst = dlDeleteTail(lst);
    dlprint(lst);

    printf("\nDi chuyen den nut thu 3 (9)\n");
    node_t* q = dlseek(lst,3);


    printf("Xoa nut sau nut thu 3 (5):\n");
    lst = dlDeleteAfter(lst, q);
    dlprint(lst);

    printf("Xoa nut truoc nut thu 3 (6):\n");
    lst = dlDeleteBefore(lst, q);
    dlprint(lst);

    printf("Xoa nut thu 3 (9):\n");
    lst = dlDeleteNode(lst, q);
    dlprint(lst);

    printf("Xoa toan bo danh sach!\n");
    lst = dlDeleteAll(lst);
    dlprint(lst);

    return 0;
}

