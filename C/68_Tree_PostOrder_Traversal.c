// Left - Right - Root
#include <stdio.h>
#include <malloc.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Inserting values in BST
struct Node* createnode(int data){
    struct Node* n;
    n=(struct Node*)malloc(sizeof(struct Node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

void postOrder(struct Node* root){
    if (root!=NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d\n",root->data);
        
    }
}

int main ()
{
    // Creation of nodes
    struct Node* p=createnode(10);
    struct Node* p1=createnode(11);
    struct Node* p2=createnode(6);
    struct Node* p3=createnode(4);
    struct Node* p4=createnode(12);
    struct Node* p5=createnode(9);


    // Linking the nodes
    p->right=p1;
    p->left=p2;
    p2->left=p3;
    p2->right=p5;
    p1->right=p4;
    p1->left=NULL;

    postOrder(p);




    
    return 0;
}
