#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "llist.h"

root_t llPrint(root_t root)
{
    for(node_t* p = root; p != NULL; p = p->next) ShowData(p -> data);
    printf("\n");
    return root;
}

// ham tao node moi
node_t* CreateNewNode (const data_t data)
{
    // tao ra va ko chua thong tin
    node_t *new_node = (node_t*)malloc(sizeof(node_t));
    if(new_node == NULL) return NULL;

    // truyen du lieu va gan phan tu tiep theo = NULL
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

// ham gan root ban dau = NULL
root_t llInit() { return NULL; }

/*================== Insert ==========================*/

// them sinh vien vao dau danh sach tu mang student ban dau
root_t llInsertHead(root_t root, const data_t data)
{
    node_t *pNewNode = CreateNewNode(data);
    (pNewNode -> next) = root;
    return (root_t)pNewNode;
}

// 1. ham them sinh vien moi + sap xep theo diem giam dan cua danh sach
// nhan tham so dau vao la root va thong tin sv moi
root_t llInsertStudent(root_t root, const data_t data){
    node_t *curr_std, *prev_std = NULL;

    node_t *newnode = (node_t *)malloc(sizeof(node_t));
    if(root == NULL) return newnode;
    newnode -> data = data;
    newnode -> next = NULL;


    if ((newnode ->data).grade > (root -> data).grade)
        {
            newnode -> next = root;
            return newnode;
        }
    else
        {
            curr_std = root;
            while (curr_std != NULL && ((newnode ->data).grade < (curr_std -> data).grade))
            {
                prev_std = curr_std;
                curr_std = curr_std -> next;
            }
            prev_std -> next = newnode;
            newnode -> next = curr_std;
            return root;
        }
}

/*================== Delete ===========================*/ 

// ham free danh sach
root_t llDeleteAll(root_t root) {
  node_t* p = NULL;
  for (; root != NULL; root = p) {
    p = root->next;
    free(root);
  }
  return NULL;
}

/*================== Tools =============================*/

void showPtrData(data_t *data)
{
    printf("%s - %s - %d\n", data->id, data->name, data->grade);
}

// 2. tim sinh vien bang id, tra ve NULL neu ko tim thay
// ham nhan tham so root (dau dsach lien ket) va id sinh vien can tim
data_t* llFindStudent(root_t root, char *id)
{
    root_t search = root;
    while (search != NULL)
    {
        if (strcmp((search -> data).id,id) == 0)
            return &(search -> data);
        search = search -> next;
    }
    return NULL;
}

// 3. xoa mot sinh vien voi id xac dinh ra khoi danh sach
// ham nhan tham so root va id sinh vien can xoa
root_t  llDeleteStudent(root_t root, char *id){
    node_t *curr_std, *prev_std = NULL;
    if (root == NULL) return root;
    curr_std = root;

    if (strcmp((curr_std->data).id,id) == 0)
    {
        root = root -> next;
        free(curr_std);
        return root;
    }

    while (curr_std != NULL &&  strcmp((curr_std->data).id,id) != 0)
    {
        prev_std = curr_std;
        curr_std = curr_std -> next;
    }

    if (curr_std != NULL)
    {
        prev_std -> next = curr_std -> next;
        free(curr_std);
    }
    return root;
}

// 4. ham thay doi diem cua sinh vien tu id cho truoc
// ham nhan tham so root, id sinh vien can xoa va diem moi
root_t llChangeGrade(root_t root, char *id, int new_grade)
{
    data_t *std = llFindStudent(root,id);
    data_t change_std;
    change_std.grade = new_grade;
    strcpy(change_std.id,id);
    strcpy(change_std.name,std->name);

    root = llDeleteStudent(root,id);
    return llInsertStudent(root,change_std);
}
