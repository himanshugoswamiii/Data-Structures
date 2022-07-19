// is the given tree a binary search Tree
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

void inOrder(struct Node* root){
    if (root!=NULL) {
        inOrder(root->left);
        printf("%d\n",root->data);
        inOrder(root->right);
        
    }
}

// Function that checks if the given tree is BST or not
// This is similar to inOrder traversal
int isBST(struct Node* root){
    static struct Node* prev=NULL;
    // static is used so that value is prev is not different for differenet calls
    if (root!=NULL) {
        // When tree has some elements
        if(isBST(root->left)!=1){
            return 0;
        }
        if(prev!=NULL && root->data<=prev->data){
            return 0;
        }
        prev=root; // This will be used after returning in the above statement in the parent iteration
        return isBST(root->right);
    }
    else {
        // When tree is empty
        return 1;
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
    p1->left=NULL;
    p1->right=p4;

    printf("Tree is BST: %d\n",isBST(p));

    inOrder(p);
    return 0;
}
