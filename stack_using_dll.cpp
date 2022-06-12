#include<iostream>
using namespace std;
#include "linkedList.cpp"

class myStack
{
	Dint d1;
public:
	void push(int val)
	{
		d1.addToTail(val);
	}
	int pop()
	{
		return d1.deleteTail();
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
	myStack st;
	st.push(4);
	st.push(5);
	cout<< st.pop()<<"\n";
	
	cout<< st.pop()<<"\n";
	
	cout<< st.pop()<<"\n";
	st.display();
	
	cout<< st.size()<<"\n";
}
