#include<iostream>
#include "stack.h"
using namespace std;

//function to display the whole Stack using only Stack ADT
void display(myStack q){
    std::cout << "\nStack is:" << std::endl;
    cout<<"Top -->";
    while(!q.isEmpty()){
        cout<<q.pop()<<endl;
    }
    cout<<endl;
}
int main(){
    cout << "Enter size of Stack"<<endl;
    int size;
    cin>>size;
    myStack q;
    cout<<"\nEnter elements of Stack seperated by spaces"<<endl;
    for(int i=0;i<size;i++){
        int num;
        cin>>num;
        q.push(num);
    }
    cout<<endl;
    display(q);
    return 0;
}
