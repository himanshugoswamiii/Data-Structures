#include<iostream>
using namespace std;
class node{
    public:
    int key;
    string data;
    node* next;
    node(int k,string s){
        key=k;
        data=s;
        next=NULL;
    }
};

class hashmap{
    public:
    node* arr[10]={NULL};
    
    void insert(int k,string s){
        //generate hashcode for given key-s
        int code=hashcode(k);

        //code compression
        int index=code%10;

        if(arr[index]==NULL){

            //first key to map this index
            arr[index]=new node(s,d);
        }
        else{

            //collision occur
            node* curr=arr[index];
            node* prev=NULL;

            //move to next node until key with enter name
            while(curr!=NULL && curr->key!=s){
                prev=curr;
                curr=curr->next;
            }
            if(curr==NULL){
                //key is not  present
                prev->next=new node(s,d);
            }
            else{
                //key present update the data
                curr->data=d;
            }
        }
    }

    void del(string s){
        //generate hashcode for given key-s
        int code=hashcode(s);

        //code compression
        int index=code%10;

        if(arr[index]==NULL){
            //map to index which is not occupied
            cout<<"Invalid Key"<<endl;
        }
        else{

            //some keys are present
            node* curr=arr[index];
            node* prev=NULL;

            //move to next node until find the given key
            while(curr!=NULL && curr->key!=s){
                prev=curr;
                curr=curr->next;
            }
            if(curr==NULL){
                //key not found
                cout<<"Invalid Key"<<endl;
            }
            else
            {
                //key found
                if(prev!=NULL){
                    //having only one key at this index
                    prev->next=curr->next;
                    delete curr;
                }
                else{

                    //multiple keys maps to this index
                    arr[index]=curr->next;
                    delete curr;
                }
            }
        
        }
    }
    float display(string s){
        //generate hashcode for given key-s
        int code=hashcode(s);

        //code compression
        int index=code%10;

        //keys not found
        if(arr[index]==NULL){
            return -1;
        }
        else{
            //some key present
            node* curr=arr[index];
            while(curr!=NULL && curr->key!=s){
                curr=curr->next;
            }
            //given key is not present
            if(curr==NULL){
                return -1;
            }
            else
            {
                //key found display the data
                return curr->data;
            }
        
        }

    }

    //generate hash code for key
    int hashcode(int k){
        int code=0;
    
        return code;
    }
};

void menu(){
    cout<<"Enter 1 for insert data"<<endl;
    cout << "Enter 2 for delete" << endl;
    cout << "Enter 3 for search" <<endl;
    cout << "Enter 0 for exit" << endl;
}

int main ()
{
    hashmap h;
    menu();
    int choice=1;
    while (choice!=0)
    {
        cout<<"Enter your choice : ";
        cin>>choice;
        cout<<endl;
        if (choice==1)
        {
            string key;
            cout<<"\nEnter name of student : ";
            cin.ignore();
            getline(cin,key);
            float data;
            cout<<"\nEnter height of the student : ";
            cin>>data;
            h.insert(key,data);
            cout<<"\n\nData inserted with key - "<<key<<" and value - "<<data<<endl<<endl;
        }
        else if (choice==2)
        {
            string key;
            cout<<"\nEnter name of student : ";
            cin.ignore();
            getline(cin,key);
            h.del(key);
            cout<<"\n\nData deleted with key - "<<key<<endl<<endl;
        }
        else if (choice==3)
        {
            string key;
            cout<<"\nEnter name of student : ";
            cin.ignore();
            getline(cin,key);
            float ans=h.display(key);
            if(ans==-1){
                cout<<"\n\nInvalid Key\n\n"<<endl;
            }
            else{
                cout<<"\n\nStudent's height - "<<ans<<endl<<endl;
            }
        }
        else if(choice==0){
            break;
        }
        else
        {
            cout<<endl<<"\nWrong input\n"<<endl;
        }
    }
    return 0;
}