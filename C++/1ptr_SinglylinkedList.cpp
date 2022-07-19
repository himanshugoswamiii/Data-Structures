// Singly Linked List Implemented with one pointer : head pointer
// A better implementation is using two pointers : one for head, one for tail
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};

class LinkedList{
    public:
        Node* head=NULL; // At starting we have a empty Linked List

        void insertAtHead(int data){
            Node* newNode=new Node(data);
            Node* ptr=head; //Renaming head because we want to make newNode head
            newNode->next=ptr;
            head=newNode;
        }

        void insertAtTail(int data){

            Node* newNode=new Node(data);

            if (head==NULL)
                // In case: Linked List is empty
            {
                head=newNode;
                
            }
            else
                // When linked-List had some elements
            {
                while(head->next!=NULL){
                    head=head->next;
                }
                head->next=newNode;
            }
        }

        void display(){
            while (head!=NULL)
            {
                cout << head->data << endl;
                head=head->next;
            }
        }

};

int main ()
{
    LinkedList L1;
    L1.insertAtTail(10);
    L1.insertAtHead(0);
    L1.insertAtHead(100);
    L1.insertAtTail(20);
    L1.insertAtTail(30);
    L1.insertAtTail(90);
    L1.display();
    return 0;
}
