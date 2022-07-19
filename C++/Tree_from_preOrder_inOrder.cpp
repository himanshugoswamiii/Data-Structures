#include <iostream>
using namespace std;
 
class node
{
    public:
    int data;
    node* left;
    node* right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

// Function for Inorder Traversal
void printInorder(node* node)
{
    if (node == NULL)
        return;

    printInorder(node->left);
 
    cout<<node->data<<" ";
 
    printInorder(node->right);
}

/* Function to find index of value in arr[start...end]*/
int findPosition(int arr[], int strt, int end, char value)
{
    int i;
    for (i = strt; i <= end; i++)
    {
        if (arr[i] == value)
            return i;
    }
    return -1; // This will never run
}
 
// ------ Main function to build the tree ----
node* buildTree(int in[], int pre[], int inStrt, int inEnd)
{
    static int preIndex = 0;
 
    if (inStrt > inEnd)
        return NULL;

    node* tNode = new node(pre[preIndex++]);
 
    if (inStrt == inEnd)
        return tNode;
 
    int inIndex = findPosition(in, inStrt, inEnd, tNode->data);
 
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd);
 
    return tNode;
}
 
// To print our inOrder and preOrder Traversals
void printArr(int Arr[],int length){
    for (int i = 0; i < length; i++) {
        cout<<Arr[i]<<" ";
    }
}


/* Driver code */
int main()
{
    int inOrd[] = {3,1,4,0,5,2};
    int preOrd[] = {0,1,3,4,2,5};
    int len = sizeof(inOrd) / sizeof(inOrd[0]);

    cout<<"\nGiven: In-Order traversal: " ;
    printArr(inOrd,len);
    cout<<"\nGiven: Pre-Order traversal: " ;
    printArr(preOrd,len);

    node* root = buildTree(inOrd, preOrd, 0, len - 1);
 
    cout << "\nInorder traversal of the constructed tree is \n";
    printInorder(root);
}
