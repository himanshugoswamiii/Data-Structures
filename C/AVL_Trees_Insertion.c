#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
};

int getHeight(struct Node* n){
    if(n==NULL)
        return 0;
    return n->height;
}

struct Node* createNode(int key){
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->key=key;
    node->left=NULL;
    node->right=NULL;
    node->height=1; // Leaf node has height 1
    return node;
}

int getBalanceFactor(struct Node* n){
    if (n==NULL) {
        return 0;
    }
    int bf=getHeight(n->left)-getHeight(n->right); // balance factor
    return bf;
}

int max(int x,int y){
    int z=(x>y)?x:y;
    return z;
}

// Right Rotate
struct Node* rightRotate(struct Node* y){
    /*       y
            / \
           x   T3
         /   \     
        T1   T2
        */
    struct Node* x=y->left;
    struct Node* T2=x->right;

    x->right=y;
    y->left=T2;

    // Update height
    y->height=max(getHeight(y->right),getHeight(y->left))+1;
    x->height=max(getHeight(x->right),getHeight(x->left))+1;

    return x;
    
}

struct Node* leftRotate(struct Node* x){
    /*        x
            /  \
          T1    y
              /   \ 
            T2    T3
           
        */
    struct Node* y=x->right;
    struct Node* T2=y->left;

    y->left=x;
    x->right=T2;

    // Update height
    y->height=max(getHeight(y->right),getHeight(y->left))+1;
    x->height=max(getHeight(x->right),getHeight(x->left))+1;

    return y;
    
}

struct Node* insert(struct Node* node,int key){

}


