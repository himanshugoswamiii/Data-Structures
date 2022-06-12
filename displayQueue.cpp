#include<iostream>
#include "queue.h"
using namespace std;

//function to display the whole queue using only Queue ADT
void display(Queue q){
    std::cout << "\nQueue is:" << std::endl;
    std::cout << "Front-->";
    while(!q.isEmpty()){
        cout<<q.front()<<" ";
        q.dequeue();
    }
    cout<<"  --> End"<<endl;
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
        q.enqueue(num);
    }
    cout<<endl;
    display(q);
    return 0;
}
