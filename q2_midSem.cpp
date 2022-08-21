#include <iostream>

#include "queue.h"

using namespace std;

void myfunc(Queue q2,int n){
    // Finding the minimum
    int x,min,temp,max;

    // For minimum value
    min=q2.dequeue();
    q2.enqueue(min);
    for (int i = 0; i < n-1; i++) {
        // Now we have 1 and 2nd element
        x=q2.dequeue();
        if (min>x)
        {
            min=x;
        }
        q2.enqueue(x);
    }

    cout << "minimum value is:" << endl;
    cout<<min<<endl;

    // Queue now is :
    q2.display();

    // For maximum value
    max=q2.dequeue();
    q2.enqueue(max);
    for (int i = 0; i < n-1; i++) {
        // Now we have 1 and 2nd element
        x=q2.dequeue();
        if (max<x)
        {
            max=x;
        }
        q2.enqueue(x);
    }
    cout << "maximum value is:" << endl;
    cout<<max<<endl;

    // Queue now is :
    q2.display();


}



int main ()
{
    Queue q1;
    q1.enqueue(5);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(21);
    q1.enqueue(10);
    q1.enqueue(2);

    q1.display();

    myfunc(q1,6);
    
    return 0;
}
