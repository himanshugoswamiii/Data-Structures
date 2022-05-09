// Insertion in Single Circular Linked List 
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

// For traversing the Linked list
void traversal(struct Node* head){
    struct Node* p=head;
    do {
        printf("%d\n",p->data);
        p=p->next;

    }while (p!=head);
}

// Insert at head
struct Node* insertAthead(struct Node* head,int value){
    // Memory Allocation
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=value;
    struct Node* p=head->next;
    // After this loop our pointer will be at the end
    while (p->next!=head) {
    p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    head=ptr; // Making head as ptr otherwise ptr will added at last
    return head;
}

int main ()
{
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;

    // Memory Allocation
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));

    head->data=10;
    head->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=fourth;

    fourth->data=40;
    fourth->next=head;

    // Traversal
    printf("Original Linked List: \n");
    traversal(head);

    int x;
    printf("Enter value to insert at head: ");
    scanf("%d",&x);
    head=insertAthead(head, x);
    printf("New linked list is: \n");
    traversal(head);
    
    return 0;
}
