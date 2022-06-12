#include<iostream>
using namespace std;
class node{
    public:
    string key;
    float data;
    node* next;
    node(string s,float d){
        key=s;
        data=d;
        next=NULL;
    }
};

class hashmap{
    public:
    int collision=0;
    node* arr[10]={NULL};
    
    int insert(string s, float d){
        //generate hashcode for given key-s
        int code=hashcode(s);

        //code compression
        int index=code%10;
        int colToInsert=0;
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
                colToInsert++;
                collision++;
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
        return colToInsert;
    }

    bool del(string s){
        bool isdeleted=true; 
        //generate hashcode for given key-s
        int code=hashcode(s);

        //code compression
        int index=code%10;

        if(arr[index]==NULL){
            //map to index which is not occupied
            isdeleted = false;
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
                isdeleted = false;
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

        return isdeleted;
    }
    float keyValue(string s){
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
    int hashcode(string key){
        int code=0;
        for(char ch : key){
            code=33*code+ch;
        }
        if(code>0){
            return code;
        }
        else
        {
            return -code;            
        }
    }

    void display(){
        int index=0;
        for(node* var : arr)
        {
            if(var!=NULL){
                cout<<index<<" : "<<var->key<<" "<<var->data;
                while(var->next){
                    var=var->next;
                    cout<<" --> "<<var->key<<" "<<var->data;
                }
                cout<<endl;
            }
            index++;
        }
    }

    int totalCollision (){
        return collision;
    }
};

void options(int choice){

}
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
    hashmap h;
    int choice=1;
    while (choice!=0)
    {
        menu();
        cout<<"Enter your choice : ";
        cin>>choice;
        cout<<endl;
        switch (choice) {
            case 1:
        {
            string key;
            cout<<"\nEnter name of student : ";
            cin.ignore();
            getline(cin,key);
            float data;
            cout<<"\nEnter height of the student : ";
            cin>>data;
            int temp = h.insert(key,data);
            cout<<"\n\nData inserted with key - "<<key<<" and value - "<<data<<endl;
            cout<< "Collision to insert : "<< temp << endl<<endl;
            break;
        }
            case 2:
        {
            string key;
            cout<<"\nEnter name of student : ";
            cin.ignore();
            getline(cin,key);
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
            string key;
            cout<<"\nEnter name of student : ";
            cin.ignore();
            getline(cin,key);
            float ans=h.keyValue(key);
            if(ans==-1){
                cout<<"\n\nInvalid Key\n\n"<<endl;
            }
            else{
                cout<<"\n\nStudent's height - "<<ans<<endl<<endl;
            }
            break;
        }
            case 4:{
            cout<<endl;
            h.display();
            cout<<endl;
            break;
        }
            case 5:{
            cout << "\n\nTotal No. of collision till Now - " << h.totalCollision() << endl << endl;
            break;
        }
        case 0:
            break;
        default:
        {
            cout<<endl<<"\nWrong input\n"<<endl;
            break;
        }
    
    }
    }
    return 0;
}
