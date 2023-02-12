#include <stdio.h>
#include <stdlib.h>

typedef int elmType;

typedef struct nodeType{
    elmType element;
    struct nodeType *left, *right;
}   node_type;

int isEmpty(node_type *root){ return root == NULL; } 
// 1 (true) if tree is empty, == 0 (false) if tree not empty
node_type *makeNULLtree(node_type *root){ root = NULL;}

int IsLeaf(node_type *root){
    if(root != NULL)
        return (root -> right == NULL) && (root->left == NULL);
    else
        return -1;
    
}

node_type *createNode(elmType element){
    node_type *newnode = (node_type *)malloc(sizeof(node_type));
    if (newnode == NULL) return NULL;
    newnode -> element = element;
    newnode -> right = NULL;
    newnode -> left = NULL;
    return newnode;
}   

node_type *LeftChild(node_type *root){
    if(root == NULL)
        return NULL;
    else 
        return root -> left;
}

node_type *RightChild(node_type *root){
    if(root != NULL)
        return root -> right;
    else 
        return NULL;
}

int nb_nodes(node_type *root){
    if(isEmpty(root))
        return 0;
    return nb_nodes(RightChild(root))+nb_nodes(LeftChild(root))+1;
}

int treeNbrLeaf(node_type *root){
    if(root == NULL) return 0;
    if(IsLeaf(root)) return 1;
    return treeNbrLeaf(RightChild(root))+treeNbrLeaf(LeftChild(root));
}

int treeInternalNode(node_type *root){
    return nb_nodes(root)-treeNbrLeaf(root);
}

int heightOftree(node_type *root){
    if ( root == NULL ) return 0;
    int leftheight = heightOftree(root->left);
    int rightheight = heightOftree(root->right);
    if(leftheight > rightheight)
        return leftheight + 1;
    else    
        return rightheight + 1;
}

void preOrder(node_type *root){
    if (root == NULL) return;
    printf("%d \t", root -> element);
    preOrder(root -> left);
    preOrder(root -> right);
}

void inOrder(node_type *root){
    if(root == NULL) return;
    inOrder(root->left);
    printf("%d \t", root->element);
    inOrder(root->right);
}

void postOrder(node_type *root){
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d \t", root->element);
}

int main(void){
    node_type *root = createNode(1);
    root -> left  = createNode(2);
    root -> right = createNode(3);
    root -> left -> left = createNode(4);
    root -> left -> right = createNode(5);

    printf("PreOrder of tree is:\n");
    preOrder(root);
    printf("\n");
    printf("Inorder of tree is:\n");
    inOrder(root); printf("\n");
    printf("postorder of tree is:\n");
    postOrder(root); printf("\n");

    printf("Node %d is leaf or not: %d\n", RightChild(root)->element, IsLeaf(RightChild(root)));
    printf("Number of node is: %d\n", nb_nodes(root));
    printf("Number of leaf is: %d\n", treeNbrLeaf(root));
    printf("Number of internal nodes is: %d\n", treeInternalNode(root));
    printf("Height if tree is: %d\n", heightOftree(root));
    return 0;
}

