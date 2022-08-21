// Better version of Code with Harry
#include<stdio.h>
#include<malloc.h>
 
struct node{
    int data;
    struct node* left;
    struct node* right;
};
 
struct node* createNode(int data){
    struct node *n; // creating a node pointer
    n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data; // Setting the data
    n->left = NULL; // Setting the left and right children to NULL
    n->right = NULL; // Setting the left and right children to NULL
    return n; // Finally returning the created node
}
 
// Traversal
void inOrder(struct  node* root){
    if (root!=NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
} 
 
// For DELETION
struct node *inOrderPredecessor(struct node* root){
    root = root->left;
    while (root->right!=NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *deleteNode(struct node *root, int value){
    // returns the new root node

    struct node* iPre;
    if (root == NULL){
        return NULL;
    }
    if (root->left==NULL&&root->right==NULL){
        if (root->data==value) {
            // found at leaf
            free(root);
            return NULL;
        }
        else{
            printf("%d: not found in Tree\n",value);
            return root;
        }
    }

    //searching for the node to be deleted
    if (value < root->data){
        root-> left = deleteNode(root->left,value);
    }
    else if (value > root->data){
        root-> right = deleteNode(root->right,value);
    }
    //deletion strategy when the node is found but not at leaf
    else{
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
}
 
int main(){
     
    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(8);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(10);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(5);
    struct node *p5 = createNode(4);
    struct node *p6 = createNode(7);
    struct node *p7 = createNode(6);
    struct node *p8 = createNode(14);

    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4  
 
    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p4->left = p5;
    p4->right = p6;
    p6->left = p7;
    p2->right = p8;

    inOrder(p);
    printf("\n");
    p=deleteNode(p, 5);
    inOrder(p);

    return 0;
}
