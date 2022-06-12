// Question 5: Here we've to change the compressio n from simple mod 10 to
// h(k)=floor(m(k mod 1)) for a constant 0<A<1
// Size: 10
#include<iostream>
#include <math.h>
using namespace std;
class node{
    public:
    int key;
    string data;
    node* next;
    node(string s,int d){
        data = s;
        key = d;
        next=NULL;
    }
};

class hashmap{
    public:
    int collision=0;
    int arrSize;
    node** arr;
    hashmap(int size){
        this->arrSize = size;
        arr = new node*[arrSize];
        for (int i = 0; i < arrSize; i++) {
            arr[i] = NULL;
        }
    }
    
    int insert(string s, int d){
        //generate hashcode for given key-s
        int code=hashcode(d);

        //code compression
        int index = code % arrSize;
        int colToInsert=0;          //collision happen to insert
        if(arr[index]==NULL){

            //first key to map this index
            arr[index]=new node(s,d);
        }
        else{

            //collision occur
            node* curr=arr[index];
            node* prev=NULL;

            //move to next node until key with enter name
            while(curr!=NULL && curr->key!=d){
                prev=curr;
                curr=curr->next;
                colToInsert++;
                collision++;
            }
            if(curr==NULL){
                //key is not  present
                prev->next=new node(s,d);
            }
            else{
                //key present update the data
                curr->data=s;
            }
        }
        return colToInsert;
    }

    bool del(int d){
        bool isdeleted=true; 
        //generate hashcode for given key-s
        int code=hashcode(d);

        //code compression
        int index = code % arrSize;

        if(arr[index]==NULL){
            //map to index which is not occupied
            isdeleted = false;
        }
        else{

            //some keys are present
            node* curr=arr[index];
            node* prev=NULL;

            //move to next node until find the given key
            while(curr!=NULL && curr->key!=d){
                prev=curr;
                curr=curr->next;
            }
            if(curr==NULL){
                //key not found
                isdeleted = false;
            }
            else
            {
                //key found
                if(prev!=NULL){
                    //multiple keys maps to this index
                    
                    prev->next=curr->next;
                    delete curr;
                }
                else{
                    //having only one key at this index or data present at index
                    
                    arr[index]=curr->next;
                    delete curr;
                }
            }
        
        }

        return isdeleted;
    }
    string keyValue(int d){
        //generate hashcode for given key-s
        int code=hashcode(d);

        //code compression
        int index = code % arrSize;

        //keys not found
        if(arr[index]==NULL){
            return "";
        }
        else{
            //some key present
            node* curr=arr[index];
            while(curr!=NULL && curr->key!=d){
                curr=curr->next;
            }
            //given key is not present
            if(curr==NULL){
                return "";
            }
            else
            {
                //key found display the data
                return curr->data;
            }
        
        }

    }

    //generate hash code for key
    int hashcode(int data){
        double intPart,fracPart;
        double A=0.137;
        fracPart=modf(data*A,&intPart);
        int index=(int)floor(10*fracPart);
        return index;
    }

    void display(){
        
        for(int i=0;i<arrSize;i++)
        {
            node* var = arr[i];
            if(var!=NULL){
                cout<<i<<" : "<<var->key<<" "<<var->data;
                while(var->next){
                    var=var->next;
                    cout<<" --> "<<var->key<<" "<<var->data;
                }
                cout<<endl;
            }
        }
    }

    int totalCollision (){
        return collision;
    }
};

void menu(){
    cout<<"\n**********************"<<endl;
    cout<<"Enter 1 for insert data"<<endl;
    cout << "Enter 2 for delete" << endl;
    cout << "Enter 3 for search" <<endl;
    cout << "Enter 4 for display" << endl;
    cout << "Enter 5 for Total No. of collision happens till now" << endl;
    cout << "Enter 0 for exit" << endl;
}

int main ()
{
    hashmap h(10);
    int choice=1;
    while (choice!=0)
    {
        menu();
        cout<<"\nEnter your choice : ";
        cin>>choice;
        cout<<endl;
        switch(choice){
            case 1:
            {
                int key;
                cout<<"\nEnter Roll No : ";
                cin>>key;
                string data;
                cout<<"\nEnter name of student : ";
                cin.ignore();
                getline(cin,data);
                int temp = h.insert(data,key);
                cout<<"\n\nData inserted with key - "<<key<<" and value - "<<data<<endl;
                cout<< "Collision to insert : "<< temp << endl<<endl;
                break;
            }
            case 2:
            {
                int key;
                cout<<"\nEnter Roll No : ";
                cin >> key;
                bool ans = h.del(key);
                if(ans){
                    cout<<"\n\nData deleted with key - "<<key<<endl<<endl;
                }
                else{
                    cout << "\n\nInvalid Key\n\n";
                }
                break;
            }
            case 3:
        {
            int key;
            cout<<"\nEnter Roll No : ";
            cin >>key;

            string ans=h.keyValue(key);
            if(ans==""){
                cout<<"\n\nInvalid Key\n\n"<<endl;
            }
            else{
                cout<<"\n\nStudent's Name - "<<ans<<endl<<endl;
            }
            break;
        }
            case 4:
        {
            cout<<endl;
            h.display();
            cout<<endl;
            break;
        }
            case 5:{
            cout << "\n\nTotal No. of collision till Now - " << h.totalCollision() << endl << endl;
            break;
        }
            case 0:{
            break;
        }
            default:
        {
            cout<<endl<<"\nInvalid input\n"<<endl;
            break;
        }
        }
    }
    return 0;
}
