// Tree given: Posr-Order and In-Order traversal
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
    return -1; // This will never be returned
}
 
// ------ Main function to build the tree ----
node* buildTree(int in[], int post[], int inStrt,
                int inEnd)
{

    static int postIndex=inEnd;
    // Base case
    if (inStrt > inEnd)
        return NULL;
 
    node* newnode = new node(post[postIndex]);
    (postIndex)--;
 
    if (inStrt == inEnd)
        return newnode;
 
    int iIndex = findPosition(in, inStrt, inEnd, newnode->data);

    newnode->right = buildTree(in, post, iIndex + 1, inEnd);
    newnode->left = buildTree(in, post, inStrt, iIndex - 1 );
 
    return newnode;
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
    int inOrd[] = { 4, 8, 2, 5, 1, 6, 3, 7 };
    int postOrd[] = { 8, 4, 5, 2, 6, 7, 3, 1 };
    int len = sizeof(inOrd) / sizeof(inOrd[0]);

    cout<<"\nGiven: In-Order traversal: " ;
    printArr(inOrd,len);
    cout<<"\nGiven: Post-Order traversal: " ;
    printArr(postOrd,len);

    node* root = buildTree(inOrd, postOrd,0, len-1);
 
    cout << "\nInorder traversal of the constructed tree is \n";
    printInorder(root);
}
