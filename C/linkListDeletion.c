#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
    /* data */
};

void traversal(struct Node* head){
    while (head!=NULL)
    {
        printf("%d\n",head->data);
        head=head->next;
    }
    
}

// Case 1: Delete the first element 
struct Node* delfirstNode(struct Node* head){
    struct Node* ptr=head;  // I'm doing this so that i can still have access of old head to free it later
    head=head->next;

    // Free the memory of ptr (i.e. first node)
    free(ptr);

    return head;
}

// Case 2: Delete at index
struct Node* delAtIndex(struct Node* head,int index){
    while (i<index)
    {
        /* code */
    }
    


}


int main(int argc, char const *argv[])
{
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));

    // Creation of a linked list
    head->data=10;
    head->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=fourth;

    fourth->data=40;
    fourth->next=NULL;

    // Traversal
    printf("Original Linked List: \n");
    traversal(head);

    // Deleting first Node
    head=delfirstNode(head);
    printf("\nLinked after Deleting the head: \n");
    traversal(head);
    
    // Deletion at a given index
    head=delAtIndex(head,2); 
    printf("\nLinked after Deleting at index 2: \n");
    traversal(head);

    return 0;
}
