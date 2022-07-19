#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int val){
            data=val;
            left=NULL;
            right=NULL;
        }
};

void inorder(Node* root){
    if (root!=NULL){
        inorder(root->left);
        cout << root->data << endl;
        inorder(root->right);
    }

}
// Insert function definition.
Node* insertTree(Node* root, int value)
{
    if (root==NULL) {
        // Insert the first node, if root is NULL.
        return new Node(value);
    }
 
    // Insert data.
    if (value > root->data) {
        // Insert right node data, if the 'value'
        // to be inserted is greater than 'root' node data.
 
        // Process right nodes.
        root->right = insertTree(root->right, value);
    }
    else {
        // Insert left node data, if the 'value'
        // to be inserted is greater than 'root' node data.
 
        // Process left nodes.
        root->left = insertTree(root->left, value);
    }
 
    // Return 'root' node, after insertion.
    return root;
}

// Searching in BST
int searchBST(Node* root,int value){
    // Return whether a element exist in tree or not
    if (root==NULL) {
        return 0;
    }
    else{
        if(root->data==value)
            return 1;
        else if (value>root->data){
            return searchBST(root->right,value);
        }
        else{
            return searchBST(root->left,value);
        }
    }
}



// BST Main class
class BST{
    public:
        Node* root;

        BST(){
            root=NULL;
        }

        void insert(int val){
            root=insertTree(root,val);
        }

        void inorderTraversal(){
            inorder(root);
            }

        void search(int val){
            cout << "Element found: "<< searchBST(root,val) << endl;
            

        }
        
};

int main ()
{
    BST T1;
    T1.insert(10);
    T1.insert(56);
    T1.insert(6);
    T1.insert(34);
    T1.inorderTraversal();

    T1.search(6);
    
    return 0;
}
