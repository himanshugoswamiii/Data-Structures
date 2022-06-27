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

int main ()
{
    /* struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    // Root Node
    p->data=10;

    // Left Node
    struct node *p1;
    p1=(struct node*)malloc(sizeof(struct node));
    // Root Node
    p1->data=1;
    p1->left=NULL;
    p1->right=NULL;
    
    // Right Node
    struct node *p2;
    p2=(struct node*)malloc(sizeof(struct node));
    // Root Node
    p2->data=15;
    p2->left=NULL;
    p2->right=NULL;

    // Root node linking to left and Right nodes
    p->left=p1;
    p->right=p2; */

    struct node* p=createnode(10);
    struct node* p1=createnode(1);
    struct node* p2=createnode(15);

    // Linking the node
    p->left=p1;
    p->right=p1;

    return 0;
}
