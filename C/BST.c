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

int findsum(struct Node* root,int l,int b,int *count){
    int sum=0;
    if (root!=NULL) {
        if (b<(root->data) & l>(root->data) ) {
            sum+=root->data;
        }
        if (b<(root->data)){
            (*count)++;
            sum+=findsum(root->left,l,b,count);
        }
        if (l>(root->data)){
            (*count)++;
            sum+=findsum(root->right,l,b,count);
        }
    }
    return sum;
}

int main ()
{
    // Creation of nodes
    struct Node* p=createnode(10);
    struct Node* p1=createnode(11);
    struct Node* p2=createnode(6);
    struct Node* p3=createnode(4);
    struct Node* p4=createnode(13);
    struct Node* p5=createnode(9);
    struct Node* p6=createnode(12);


    // Linking the nodes
    p->right=p1;
    p->left=p2;
    p2->left=p3;
    p2->right=p5;
    p1->right=p4;
    p1->left=NULL;
    p4->left=p6;
    p4->right=NULL;

    int l=13;
    int b=6;
    int c=0;
    int sum=findsum(p,l,b,&c);
    printf("Sum is: %d \n",sum);
    printf("Count is: %d\n",c);
    return 0;
}
