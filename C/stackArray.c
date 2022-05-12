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
    for(int i=0;i<=(ptr->top);i++){
        printf("%d\n",ptr->arr[i]);
    }

}

// Push()
void push(struct stack *ptr,int val){ // Here it's call by refernce
    if (isFull(ptr)==1) {
        printf("Stack Overflow\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}

int main(){
    // Create a stack
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    s->size=80;
    s->top=-1;
    s->arr=(int *)malloc(s->size * sizeof(int)); // Memory allocation for the array

    // Pushing an element manually
    s->arr[0]=5;
    (s->top)++;
    s->arr[1]=6;
    (s->top)++;
    int isem=isEmpty(s);
    int isfu=isFull(s);

    // Stack is empty/ Full
    if(isem==1){
        printf("Stack is empty\n");
    }
    else {
        printf("Stack is not empty \n");   
    }

    if(isfu==1){
        printf("Stack is Full\n");
    }
    else {
    printf("Stack is not full\n");
    }

    showStack(s);

    // 
    return 0;
}
