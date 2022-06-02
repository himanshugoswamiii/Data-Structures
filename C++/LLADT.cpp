#include <cstdio>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
using namespace std;
class Node {
    int data;
    class Node* next;
};
class LinkedList{
    int count=3; // for counting no of elements in the Linked list

    // Check is linked list is empty
    int isEmpty(){
        if (head==NULL)
            return 1;
        else
            return 0;
    }

    // For traversing the Linked list
    void traversal(){
        printf("\n --- LINKED LIST is --- \n");
        while (head!=NULL)
        {
            printf("%d\n",head->data);
            head=head->next;
        }
        
    }

    //          Insert at first position
    // This function will return the pointer of the new node
    struct Node* insertAtFirst(int data) {
        // First create a node in the memory
        struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
        ptr->next=head;
        ptr->data=data;
        count+=1;
        return ptr;
    }


    // Case 2: Insert at Index
    struct Node* insertAtindex(int data,int index){
        // Memory allocation for the new node
        struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
        struct Node* p=head;
        int i=0;
        while (i!=index-1) // Taking head to the index
        {
            p=p->next;
            i++;
        }
        ptr->data=data;
        ptr->next=p->next;
        p->next=ptr; // if index is 2 then p is at 1
        count+=1;
        return head;
    }

    // Case 3: Insert at end
    struct Node* insertAtend(int data){
        // Memory allocation for the new node
        struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
        // Move the pointer to the end
        struct Node* p=head;
        while (p->next!=NULL) // Note this and check the difference b/w p!=NULL
        {
            p=p->next;
        }
        p->next=ptr;
        ptr->data=data;
        ptr->next=NULL;
        
        count+=1;
        return head;

    }

    // Search element
    int searchel(int el){
        while (head!=NULL)
        {
            if (head->data==el){
                return true;
            }
            head=head->next;
        }

        return false;
        
    }

    // Case : Delete at index
    // Case 1: Delete the first element 
    delfirstNode(){
        if (isEmpty(head)==1){
            printf("\n Linked List is Empty \n");
        }
        else {
            count--;
            struct Node* ptr=head;  // I'm doing this so that i can still have access of old head to free it later
            head=head->next;

            // Free the memory of ptr (i.e. first node)
            free(ptr);

        }
        return ;
    }

    // Case 2: Delete at index
    void delAtIndex(struct Node* head,int index){
        if (isEmpty(head)==1){
            printf("\n Linked List is Empty \n");
        }
        else if (index>=count) {
            printf("Index doesn't exist\n");
        }
        else {
            count--;
            int i=0;
            while (i<index-1)
            {
                head=head->next;
                i++;
            }
            struct Node* ptr=head->next;
            head->next=ptr->next;
            free(ptr);
        }
    }

    // Case 3: Delete from the end
    void delEnd(struct Node* head){
        if (isEmpty(head)==1){
            printf("\n Linked List is Empty \n");
        }
        else{
            count--;
            struct Node* p=head;
            struct Node* q=head->next;
            while(q->next!=NULL)
            {
                p=p->next;
                q=q->next;
            }
            p->next=NULL; // Before deletion we'll point p to NULL
            free(q);

        }
    }

    // Linked List size
    int sizeList(){
        int size=sizeof(struct Node)*count;
        return size; // returning the size of the Linked list
    }
}
