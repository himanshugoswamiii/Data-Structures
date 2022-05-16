#include <stdio.h>
#include <stdlib.h>
struct stack {
    int size;
    int top; // Top element of the stack
    int *arr; // integer array
};
// check if the stack is empty
int isEmpty(struct stack *ptr){
    if (ptr->top==-1){
        return 1;
    }
    else {
        return 0;
    }
}

int isFull(struct stack *ptr){
    if (ptr->top==ptr->size-1){
        return 1;
    }
    return 0;
}

void showStack(struct stack *ptr){
    printf("\n --- Stack is --- \n");
    for(int i=0;i<=(ptr->top);i++){
        printf("%d\n",ptr->arr[i]);
    }

}

// Push()
void push(struct stack *ptr,int val){ // Here it's call by refernce
    if (isFull(ptr)==1) {
        printf("\nStack Overflow\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}

// Pop() - delete the last element and return that as well
int pop(struct stack *ptr){
    int val=-1; // Default is for underflow
    if (isEmpty(ptr)==1){
        printf("\nStack Underflow. Can't delete\n");
        return val;
    }
    else{
        val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int main(){
    // Create a stack
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    s->size=5;
    s->top=-1;
    s->arr=(int *)malloc(s->size * sizeof(int)); // Memory allocation for the array

    // Pushing an element manually
    s->arr[0]=5;
    (s->top)++;
    s->arr[1]=6;
    (s->top)++;

    // Disaplay for the user
    int ch=1;
    while (ch) {

        printf("Enter\n 1 to show the stack\n 2 to push into the stack\n 3 to pop from the stack \n");
        int choice;
        scanf("%d",&choice);
        int pval; // popped value
        int val;
        switch (choice) {
            case 1: 
                showStack(s);
                break;
            case 2: 
                printf("Enter the value to be inserted into stack\n");
                scanf("%d",&val);
                push(s,val);
                break;
            case 3:
                pval=pop(s);
                printf("Popped element is: %d \n",pval);
                
                break;
            default:
                break;
        }
        printf("Enter 1 to continue 0 to exit \n");
        scanf("%d",&ch);
    }

    return 0;
}
