/*
    Ho va ten: Nguyen Tuan Thanh
    MSSV: 20210800
    Ma lop: 135307
    Ngay hoan thanh: 8-12-2022
    Muc tieu cua chuong trinh:
        + Tao danh sach don sap xep theo thu tu giam dan diem sinh vien
        Chương trình 1.
            a. Tạo một danh sách liên kết có thứ tự theo grade từ lớn đến nhỏ.
            b. Sử dụng tìm kiếm nhị phân, hãy viết hàm trả về con trỏ đến student tìm thấy, NULL nếu không tìm thấy có 
                prototype như sau (key là grade):
            student_t* binarySearchByGrade(root_t lst, const int key); (Line: 166)
            c. Viết chương trình chính thử nghiệm các hàm
        Chương trình 2.
            a. Tạo danh sách liên kết có thứ tự theo name từ nhỏ đến lớn (theo alphabet)
            b. Sử dụng tìm kiếm nhị phân, hãy viết hàm trả về con trỏ đến student tìm thấy, NULL nếu không tìm thấy có 
                prototype như sau (key là name)
            student_t* binarySearchByName(root_t lst, char* key); (Line: 200)
            c. Viết chương trình chính thử nghiệm các hàm trên.
    
    KET QUA CHAY CHUONG TRINH:
        Printf all 
        005 - sv5 - 10
        003 - sv3 - 6
        004 - sv4 - 5
        001 - sv1 - 2
        002 - sv2 - 1

        Student has grade = 6 is: 
        003 - sv3 - 6
        Student has name sv2 is:
        002 - sv2 - 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOT_FOUND (-1)

typedef struct {
    char id[20];
    char name[32];
    int grade;
}   data_t;

// record structure
typedef struct node_s {
    data_t data; // tao mot thuc te cua kieu cau truc data
    struct node_s *next;
}   node_t, *root_t; // tao con tro tro  den phan tu dau tien

typedef data_t T;

/*============== Adapt to new problems ================*/

void ShowData (const data_t data);

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

/*============= Functions ================*/ 

// ham hien thi thong tin sinh vien
void ShowData (data_t data)
{
    printf("%s - %s - %d\n", data.id, data.name, data.grade);
}

// ham in danh sach lien ket
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


// ham them sinh vien moi theo thu tu giam dan cua diem
root_t llInsertStudent(root_t root, const data_t data){
    node_t *curr_std, *prev_std = NULL;

    node_t *newnode = (node_t *)malloc(sizeof(node_t));
    newnode -> data = data;
    newnode -> next = NULL;
    if(root == NULL) return newnode;


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

/*===================== Search =======================*/

root_t middle(root_t start, root_t last)
{
    if (start == NULL)
        return NULL;
 
    root_t slow = start;
    root_t fast = start -> next;
 
    while (fast != last)
    {
        fast = fast -> next;
        if (fast != last)
        {
            slow = slow -> next;
            fast = fast -> next;
        }
    }
 
    return slow;
}


// ham tim kiem sinh vien theo diem su dung tim kiem nhi phan
T* binarySearchByGrade(root_t root, int key)
{
    root_t last = NULL;
 
    do
    {
        // find middle
        root_t mid = middle(root, last);
 
        // if middle is empty
        if (mid == NULL)
            return NULL;
 
        if ((mid -> data).grade == key)
            return &(mid -> data);
 
        // if value is more than mid
        else if ((mid -> data).grade > key)
            root = mid -> next;
 
        // if the value is less than mid.
        else
            last = mid;
 
    } while (last == NULL ||
             last != root);
 
    // value not present
    return NULL;
}


// ham tim kiem sinh vien theo ten su dung tim kiem nhi phan

T* binarySearchByName(root_t root, char* key)
{
    root_t last = NULL;
 
    do
    {
        // find middle
        root_t mid = middle(root, last);
 
        // if middle is empty
        if (mid == NULL)
            return NULL;
 
        if (strcmp((mid -> data).name, key) == 0)
            return &(mid -> data);
 
        else if ((strcmp((mid -> data).name, key) != 0))
            root = mid -> next;
 
        else
            last = mid;
 
    } while (last == NULL ||
             last != root);
 
    // value not present
    return NULL;
}

/*================ Main function ====================*/ 

int main (void)
{
    data_t student[] = {{"001", "sv1", 2},
                        {"002", "sv2", 1},
                        {"003", "sv3", 6},
                        {"004", "sv4", 5},
                        {"005", "sv5", 10}};
    // tao root (head) = null
    root_t lst = llInit();
    // gan thong tin cho danh sach vao dau dsach
    for(int i=0; i < sizeof(student)/sizeof(student[0]); i++)
        lst = llInsertStudent(lst, student[i]);
    printf("\n Printf all \n");
    llPrint(lst);

    // find student with grade
    printf("Student has grade = 6 is: \n");
    data_t* pStudent = binarySearchByGrade(lst, 6);
    if (pStudent == NULL) printf("Not found!\n");
    else
        showPtrData(pStudent);

    // find student with name
    char std_name[] = "sv2";
    printf("Student has name %s is:\n", std_name);
    data_t* qStudent = binarySearchByName(lst, std_name);
    if (pStudent == NULL) printf("Not found!\n");
    else
        showPtrData(qStudent);

    // giai phong bo nho khi ket thuc chuong trinh
    lst = llDeleteAll(lst);
    return 0;
}