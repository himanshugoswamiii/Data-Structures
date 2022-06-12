#include<iostream>
using namespace std;
class Node
{
public:
	int data;
	Node *prev=NULL,*next=NULL;
	Node(int data=0)
	{
	  	this->data=data;
	}
	friend class Dint;
};

class Dint
{
	public:
	Node *head,*tail;
	int size;
		Dint()
		{
			head=NULL;
			tail=NULL;
		    size=0;
		}
		void incsize()
		{
			size++;
		}
		void decsize()
		{
			size--;
		}
		int len()
		{
			return size;
		}
		void addToTail(int d)
		{
			incsize();
			Node *temp=new Node(d);
			if(head!=NULL)
			{
				tail->next=temp;
				temp->prev=tail;
				tail=temp;
			}
			else
			{
				head=temp;
				tail=temp;
			}
		}
		
		void addToHead(int d)
		{
			incsize();
						Node *temp=new Node(d);
			if(head!=NULL)
			{
                head->prev=temp;
                temp->next=head;
                head=temp;
			}
			else
			{
				head=temp;
				tail=temp;
			}
		}
		
		void insertAt(int d,int i)
		{
			if((i>len()+1)||(i<=0))
			{
				cout<< "invalid index...............\n";
			}
			else
			{

				Node*temp=new Node(d);
				if(i==1)
				{
					addToHead(d);
				}
				else if(i==len()+1)
				{
					addToTail(d);
				}
				else
				{
					int ind=1;
					Node*curr=head;
					while(ind<i-1)
					{
						ind++;
						curr=curr->next;
					}
					temp->next=curr->next;
					temp->prev=curr;
					curr->next->prev=temp;
					curr->next=temp;
							incsize();
				}
						
			}
		}
		int deleteHead()
		{
			int val=-1;
			Node *temp=head;
			if(len()>1)
			{
				head=head->next;
				head->prev=NULL;
				val=temp->data;
				delete temp;
				decsize();
			}
			else
			{
				head=NULL;
				tail=NULL;
				if(len()==1)
				{
					val=temp->data;
					delete temp;
					decsize();
				}
			}
			return val;
		}
		
		int deleteTail()
		{
						int val=-1;
			Node *temp=tail;
			if(len()>1)
			{
				tail=tail->prev;
				tail->next=NULL;
				val=temp->data;
				delete temp;
				decsize();
			}
			else
			{
				head=NULL;
				tail=NULL;
				if(len()==1)
				{
					val=temp->data;
					delete temp;
					decsize();
				}
			}
			return val;
		}
		int deleteIndex(int i)
		{
			int val=-1;
			if((i<=0)||(i>len()))
			{
				cout<< "invalid index...............\n";
			}
			else
			{
				if(i==1)
				{
				   val=deleteHead();	
				}
				else if(i==len())
				{
					val=deleteTail();
				}
				else
				{
				   int ind=1;
				   Node *curr=head;
				   while(ind<i-1)
				   {
					curr=curr->next;
					ind++;
				   } 
			    	Node *temp=curr->next;
				    curr->next=temp->next;
				    temp->next->prev=curr;
				    val=temp->data;
				    delete temp;
				    decsize();
				}
			}
			return val;
		}
		void display()
		{
			Node*temp=head;
			while(temp!=NULL)
			{
			  	cout<< temp->data<<" ";
			  	temp=temp->next;
		    }		
		    cout<< "\n";
		}



		
};


//---------------- Using my Stack -------------
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
	
    bool isEmpty(){
        if(d1.head==NULL){
            return true;
        }
        else
            return false;
    }

    int front(){
        if (d1.head==NULL){
            return -1;
            }
        else{
        return (d1.head)->data;
        }

    }
};
