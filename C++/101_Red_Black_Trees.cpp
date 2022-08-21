#include <iostream>
using namespace std;

class Node{
    public:
    int key;
    Node* left;
    Node* right;
    int color;
    Node* parent;
    Node(int value){
        key=value;
        color=0; // 0 -> for Red
        left=nullptr;
        right=nullptr;
        parent=nullptr;
    }
};

// In order traversal
void inOrder(Node* root){
    if (root!=nullptr) {
        inOrder(root->left);
        cout << root->key << " " << root->color << endl;
        inOrder(root->right);
    }
}

class RBTree{
    public:
        Node* root=nullptr; // By default root is null

        void insert(int val){

            Node* temp=root; 
            Node* prev=nullptr;

                // When tree has atleast 1 element
            while (temp!=nullptr)
            {
                prev=temp;
                if (val<temp->key)
                {
                    temp=temp->left;
                }
                else if (val>temp->key)
                {
                    temp=temp->right;
                }
                else{
                    cout << "Value is already there" << endl;
                    return;
                }
            }

            Node* node=new Node(val);

            if (prev==nullptr){
                // When tree is empty
                root=node;
                root->color=1; // color root as black
            }
            else if(val<prev->key){
                prev->left = node;
            }
            else{
                prev->right = node;
            }
        }
        // End of insert


        void display(){
            inOrder(root);
        }


};

int main ()
{
    RBTree myTree;
    myTree.insert(20);
    myTree.insert(30);
    myTree.insert(1);
    myTree.insert(6);

    myTree.display();
    
    return 0;
}
