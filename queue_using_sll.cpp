#include<iostream>
using namespace std;
#include "linkedList.cpp"

class queue
{
	Dint d1;
public:
	void enqueue(int val)
	{
		d1.addToTail(val);
	}
	int dequeue()
	{
		return d1.deleteHead();
	}
	void display()
	{
		d1.display();
	}
	int size()
	{
		return d1.len();
	}
	
};
int main()
{ 
	queue st;
	st.enqueue(4);
	st.enqueue(5);
	cout<< st.dequeue()<<"\n";
	
	cout<< st.dequeue()<<"\n";
	
	cout<< st.dequeue()<<"\n";
	st.display();
	
	cout<< st.size()<<"\n";
}
