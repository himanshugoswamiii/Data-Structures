#include<iostream>
#include "queue.h"
using namespace std;

Queue sortq(Queue q,int size){
    // return a sorted Queue

    //auxiliary Queue
    Queue newq;
    while(!q.isEmpty()) {
        //sorting Queue using selection sort

        //taking first element to be minimum
        int mini=q.dequeue();
        
        //removing front and decrement size
        size--;

        //now finding minimum element
        for(int i=0;i<size;i++) {
            int temp=q.dequeue();
            if(temp<mini){
                q.enqueue(mini);
                mini=temp;
            }
            else{
                q.enqueue(temp);
            }
        }

        //insert minimum element in auxiliary array
        newq.enqueue(mini);
    }
    return newq;
}


int main(){
    cout << "Enter size of Queue"<<endl;
    int size;
    cin>>size;
    Queue q;
    cout<<"\nEnter elements of Queue seperated by spaces"<<endl;
    for(int i=0;i<size;i++){
        int num;
        cin>>num;
        q.enqueue(num); // enqueue is defined in queue.h
    }
    cout<<endl;
    //q.printArr();
    q=sortq(q,size);
    cout<<"\n Sorted Queue is: ";
    q.display(); // display is int the queue.h file
    return 0;
}
