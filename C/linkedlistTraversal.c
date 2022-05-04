#include <stdio.h>
#include <stdlib.h> // Because we're using malloc
struct Node {
    int data;
    struct Node* next;
};
void traversal(struct Node* ptr)
{
    while (ptr!=NULL) {
        printf("Element is: %d\n",ptr->data);
        ptr=ptr->next;
    }
}
int main ()
{
    struct Node* head;
    struct Node* second;
    struct Node* third;

    // Dynamic Memory allocation for nodes in heap
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));

    head->data=7;
    head->next=second;

    second->data=11;
    second->next=third;

    third->data=15;
    third->next=NULL;

    // Linked list traversal
    traversal(head);


    return 0;
}
