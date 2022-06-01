#include <cstdio>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
using namespace std;
int count=3; // for counting no of elements in the Linked list
struct Node {
    int data;
    struct Node* next;
};

// Check is linked list is empty
int isEmpty(struct Node* head){
    if (head==NULL)
        return 1;
    else
        return 0;
}

// For traversing the Linked list
void traversal(struct Node* head){
    printf("\n --- LINKED LIST is --- \n");
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
    count+=1;
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
    count+=1;
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
    
    count+=1;
    return head;

}

// Case 4: Insert after Node
// Here Given : struct Node* ptr
void insertAfterNode(struct Node* prevNode,int data){
    // Memory allocation for new node
    struct Node* newN=(struct Node*)malloc(sizeof(struct Node));
    newN->next=prevNode->next;
    newN->data=data;
    prevNode->next=newN;
    count+=1;
    // Here we're not returning the head. We don't need that
}

// Search element
int searchel(struct Node* head,int el){
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
struct Node* delfirstNode(struct Node* head){
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
    return head;
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

    int x; // for element insertion
    int idex; // for the index
    int c=1;
    int el; // For searching the element
    int choice; // For switch case-choice
    int dIND; // Index for deletion
    // 
    do
    {
        printf("\nPress :\n");
        printf("1. Display the linked list\n");

        cout << "\n-----------Insertion --------------" << endl;
        printf("2. Insertion into the linked list at head\n");
        printf("3. Insertion into the linked list at end\n");
        printf("4. Insertion into the linked list at a position\n");
        printf("5. Demonstration of insertion after a particular node\n");

        cout << "\n-----------Deletion --------------" << endl;
        printf("6. Deletion into the linked list at head\n");
        printf("7. Deletion into the linked list at end\n");
        printf("8. Deletion into the linked list at a position\n");

        cout << "\n-----------Options -------------" <<endl;
        printf("9. Search in the linked list\n");
        printf("10. Check is the linked list is empty\n");
        printf("11. Size and Length of linked List \n");

        std::cout << "\n----------- Exit --- " << std::endl;
        printf("Press 0 to exit: \n");


        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            traversal(head);
            break;
        case 2:
            printf("Enter the element\n");
            scanf("%d",&x);
            head=insertAtFirst(head,x);
            break;
        case 3:
            printf("Enter the element\n");
            scanf("%d",&x);
            head=insertAtend(head,x);
            break;
        case 4:
            printf("Enter the element and the index using space : \n");
            scanf("%d%d",&x,&idex);
            head=insertAtindex(head,x,idex);
            break;
        case 5:
            printf("Enter the element to be inserted after third node: \n");
            scanf("%d",&x);
            insertAfterNode(third,x);
            break;
        
        case 6:
            head=delfirstNode(head);
            break;

        case 7:
            delEnd(head);
            break;

        case 8:
            cout<<"Insert the index: "<<endl;
            cin>>dIND;
            delAtIndex(head,dIND);
            break;
        
        case 9: {
            // Searching the element
            printf("\n Enter element to search: ");
            scanf("%d",&el);
            int y=searchel(head,el); // Calling the search
            printf("\n Element exist: ");
            if (y==1){
                printf("True \n");
            }
            else{
                printf("False");
            }
            break;

            }
        case 10:
            // Check if linked list is empty
            printf("\n Linked list is empty? : %d\n",isEmpty(head));
            break;
        case 11:
            // Size of the linked list
            printf("\nSize of the linked list is: %d \n",sizeList());
            printf("Length of the linked List is: %d \n",count);
            break;
        case 0: // Exit the program
            c=0;
        default:
            break;
        }

    } while (c==1);
    return 0;
}
