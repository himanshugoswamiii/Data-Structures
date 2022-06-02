#include <cstdio>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LLADT.cpp"

class stack{

    Node* 

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



