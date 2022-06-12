#include <cstdio>
#include <iostream>
using namespace std;
class Queue{
    public:
   
    int *arr;
    int size;
    int rear;
    int front;
   
    //constructor
   
    Queue(int s){
        arr=new int[s];
        rear=-1;
        size=s;
    }
   
    //enqueue an element if Queue is not full
   
    void enqueue(int num){
        //insert element if size of Queue is not full
        if(rear+1<=size-1){
            arr[++rear]=num;
        }
        //if Queue is full
        else
        cout<<"Queue Overflow";
    }
   
    //return and remove last inserted element if existed
   
    int dequeue(){
        //return -1 if nothing is in Queue
        if(rear<0){
            cout<<"Queue underflow";
            return -1;
        }
        else{
            //storing rear element
            int temp=arr[front];
            //decrement rear
            front=front+1;
            //returning rear element
            return temp;
        }
    }
   
    //return last inserted element
   
    int display(){
        //return -1 if nothing is in Queue
        if(rear<0){
            cout<<"Queue underflow";
            return -1;
        }
        else{
            //returning rear Element
            return arr[rear];
        }
    }
   
    //return true if Queue is empty otherwise return false
   
    bool isEmpty(){
        if(rear<0){
            return true;
        }
        else
            return false;
    }

    void printArr(){
        if (isEmpty()==true){
            printf("Queue is empty\n");
        }
        else
        {
            cout<<"\nMy Queue is: "<<endl;
            for (int i=front;i<=rear;i++){
                printf("%d\n",arr[i]);
            }
        }
    }
};
void menu(){
    cout<<"Enter 1 : To add an element\n";
    cout<<"Enter 2 : To remove an element\n";
    cout<<"Enter 3 : To display rear element\n";
    cout<<"Enter 4 : To check Queue is empty or not\n";
    cout<<"Enter 5 : To display the queue\n";
    cout<<"Enter 0 : To Exit\n";
}
int main() {
    int n;
    cout<<"Enter the size of Queue"<<endl;
    cin>>n;
    Queue myQueue(n);               //Constructing Queue
    int num=1;
   
    //display menu
   
    menu();
   
    //Driver's code
    while(num!=0){
        cout<<"\nenter your choice : ";
        cin>>num;
        if(num==1){
            int k;
            cout<<"\nEnter an element : ";
            cin>>k;
            myQueue.enqueue(k);
            cout<<"\n----****Element inserted****----\n";
        }
        else if(num==2){
            cout<<"\n----****Element removed****----\n"<<myQueue.dequeue();
        }
        else if(num==3){
            cout<<"\nrear ---> "<<myQueue.display()<<endl;
        }
        else if(num==4){
            if(myQueue.isEmpty()){
                cout<<"\n----****Queue is empty****----\n";
            }
            else
                cout<<"\n----****Queue is not empty****----\n";
        }
        else if(num==5){
            myQueue.printArr();
        }
        else if(num==0){
            break;
        }
        else{
            cout<<"\n----****Wrong Input****----\n";
        }
    }

return 0;
}
