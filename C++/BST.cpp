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
        // Insert the first Node, if root is NULL.
        return new Node(value);
    }
 
    // Insert data.
    if (value > root->data) {
        // Insert right Node data, if the 'value'
        // to be inserted is greater than 'root' Node data.
 
        // Process right Nodes.
        root->right = insertTree(root->right, value);
    }
    else {
        // Insert left Node data, if the 'value'
        // to be inserted is greater than 'root' Node data.
 
        // Process left Nodes.
        root->left = insertTree(root->left, value);
    }
 
    // Return 'root' Node, after insertion.
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

/* Given a non-empty binary search tree, return the Node
with minimum key value found in that tree. Note that the
entire tree does not need to be searched. */
Node* minValueNode(struct Node* Node)
{
    struct Node* current = Node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

/* Given a binary search tree and a data, this function
deletes the data and returns the new root */
Node* deleteNode(Node* root, int data)
{
    // base case
    if (root == NULL)
        return root;
 
    // If the data to be deleted is
    // smaller than the root's
    // data, then it lies in left subtree
    if (data < root->data)
        root->left = deleteNode(root->left, data);
 
    // If the data to be deleted is
    // greater than the root's
    // data, then it lies in right subtree
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
 
    // if data is same as root's data, then This is the Node
    // to be deleted
    else {
        // Node has no child
        if (root->left==NULL and root->right==NULL)
            return NULL;
       
        // Node with only one child or no child
        else if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
 
        // Node with two children: Get the inorder successor
        // (smallest in the right subtree)
        Node* temp = minValueNode(root->right);
 
        // Copy the inorder successor's content to this Node
        root->data = temp->data;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
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

        void deleteVal(int idata){
            deleteNode(root,idata);

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
    T1.deleteVal(34);
    T1.inorderTraversal();

    T1.search(6);
    
    return 0;
}
