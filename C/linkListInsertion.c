#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

// For traversing the Linked list
void traversal(struct Node* head){
    while (head!=NULL)
    {
        printf("%d\n",head->data);
        head=head->next;
    }
    
}

//          Insert at first position
// This function will return the pointer of the new node
struct Node* insertAtFirst(struct Node *head, int data) {
    // First create a node in the memory
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}


// Case 2: Insert at Index
struct Node* insertAtindex(struct Node *head, int data,int index){
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
    return head;
}

// Case 3: Insert at end
struct Node* insertAtend(struct Node* head,int data){
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
    
    return head;

}

// Case 4: Insert after Node
// Here Given : struct Node* ptr
void insertAfterNode(struct Node* prevNode,int data){
    // Memory allocation for new node
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    new->next=prevNode->next;
    new->data=data;
    prevNode->next=new;
    // Here we're not returning the head. We don't need that
}

int main(int argc, char const *argv[])
{
    struct Node* head;
    struct Node* second;
    struct Node* third;
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));

    head->data=10;
    head->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=NULL;

    // Traversal
    printf("Original Linked List: \n");
    traversal(head);

    // Insertion at the start
    head=insertAtFirst(head,0);
    printf("\n New Linked list after insertion at start is \n");
    traversal(head);

    // Insertion at a given index
    head=insertAtindex(head,50,2);
    printf("\n New Linked list after insertion at index %d is:\n",2);
    traversal(head);

    // Insertion at the end
    head=insertAtend(head,100);
    printf("\n New Linked list after insertion at the end is:\n");
    traversal(head);

    // Insertion after given node
    insertAfterNode(second,99);
    printf("\n New Linked list after insertion at the 2nd place is:\n");
    traversal(head);

    return 0;
}
// 
