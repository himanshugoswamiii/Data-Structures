#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* insertatfirst(struct Node* head,int new){
    // Memory allocation for new node
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    // A function which returns the new head
    ptr->next=head;
    ptr->data=new;
    return ptr;
}
void traversal(struct Node* head){
    while (head->next!=NULL) {
    printf("Element: %d \n",head->data);
    head=head->next;
    }
}
int main ()
{
    // Create nodes
    struct Node* head;
    struct Node* second;
    struct Node* third;
    // Create a memory for the nodes;
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));

    // First three Nodes
    head->data=7;
    head->next=second;

    second->data=11;
    second->next=third;

    third->data=15;
    third->next=NULL;

    traversal(head);
    head=insertatfirst(head, 100);
    traversal(head);
    return 0;
}
