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
void delAtIndex(struct Node* head,int index){
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

// Case 3: Delete from the end
void delEnd(struct Node* head){
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

// Case 4: Delete after a Node
struct Node* delValue(struct Node* head,int val){
    struct Node* p=head;
    struct Node* q=head->next;
    while (q->data!=val) {
        // If the value is at the head position
        if (p->data==val){
            head=p->next;
            return head;
        }
        // If we don't find the element
        if (q->next==NULL) { 
        printf("\n --- VALUE NOT FOUND ---");
        return head;
        }
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}


int main(int argc, char const *argv[])
{
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;
    struct Node* fifth;
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));
    fifth=(struct Node*)malloc(sizeof(struct Node));

    // Creation of a linked list
    head->data=10;
    head->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=fourth;

    fourth->data=40;
    fourth->next=fifth;

    fifth->data=50;
    fifth->next=NULL;

    // Traversal
    printf("Original Linked List: \n");
    traversal(head);

    // Deleting first Node
    head=delfirstNode(head);
    printf("\nLinked List after Deleting the head: \n");
    traversal(head);
    
    // Deletion at a given index
    int i=2;
    delAtIndex(head,i); 
    printf("\nLinked List after Deleting at index %d: \n",i);
    traversal(head);

    // Deletion from the end
    delEnd(head); 
    printf("\nLinked List after Deleting from the end: \n");
    traversal(head);

    // Delete a node with given value
    int val;
    printf("\n Enter the value to be deleted: ");
    scanf("%d",&val);
    head=delValue(head,val);
    printf("\nLinked List after Deleting node with value: %d \n",val);
    traversal(head);

    return 0;
}
