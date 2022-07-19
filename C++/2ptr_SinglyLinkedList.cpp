// Singly Linked List Implemented with two pointer : head pointer, tail pointer
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
        Node* head;
        Node* tail;
        int size;
        
        LinkedList(){
            head=NULL;
            tail=NULL;
            size=0;
        }

        void insertAtHead(int data){
            Node* newNode=new Node(data);
            Node* ptr=head; //Renaming head because we want to make newNode head
            newNode->next=ptr;
            head=newNode;

            if (tail==NULL)
            // When Linked-List is empty
            {
                tail=newNode;
            }
        }

        void insertAtTail(int data){

            Node* newNode=new Node(data);

            if (tail==NULL)
            // In case: Linked List is empty
            {
                tail=newNode;
                head=tail; // We need to do this other head will still point to NULL
                
            }

            else
            // When linked-List had some elements
            {
                while(tail->next!=NULL){
                    tail=tail->next;
                }
                tail->next=newNode;
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
    L1.insertAtTail(500);
    L1.insertAtHead(0);
    L1.insertAtHead(100);
    L1.insertAtTail(20);
    L1.insertAtTail(30);
    L1.insertAtTail(90);
    L1.display();
    return 0;
}
