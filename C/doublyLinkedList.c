// Here we've info of previous node as well
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};

// For traversing the Linked list
void traversal(struct Node* head){
    printf("\n --- LINKED LIST is --- \n");
    while (head!=NULL)
    {
        printf("%d\n",head->data);
        head=head->next;
    }
    
}
int main(){
    struct Node* first;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;

    first=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));

    first->prev=NULL;
    first->data=10;
    first->next=second;

    second->prev=first;
    second->data=20;
    second->next=third;

    third->prev=second;
    third->data=30;
    third->next=fourth;

    fourth->prev=third;
    fourth->data=30;
    fourth->next=NULL;

    printf("Our Original linked list \n");
    traversal(first);

}