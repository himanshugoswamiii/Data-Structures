// Root - Left - Right
#include <stdio.h>
#include <malloc.h>

// Node of the tree
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function that creates the nodes
struct node* createnode(int data){
    struct node* n;
    n=(struct node*)malloc(sizeof(struct node)); // Memory Allocation
    n->right=NULL;
    n->left=NULL;
    n->data=data;
    return n;
}

// Pre-Order Traversal
void preorder(struct node* root){
    if(root!=NULL){
        printf("%d ->",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main ()
{
    struct node* p=createnode(4);
    struct node* p1=createnode(1);
    struct node* p2=createnode(15);
    struct node* p3=createnode(5);
    struct node* p4=createnode(2);


    // Linking the nodes
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;

    // Pre-Order Traversal
    preorder(p);

    return 0;
}
