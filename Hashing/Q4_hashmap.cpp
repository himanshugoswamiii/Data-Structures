#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data = data;
        next = NULL;
    }
};

class hashmap
{
public:
    int arrSize;
    node** arr;
    int totalInsertProbe = 0;
    int totalSearchProbe = 0;
    
    hashmap(int arrSize){
        this->arrSize = arrSize;
        arr = new node*[arrSize];
        for(int i=0;i<arrSize;i++){
            arr[i]=NULL;
        }
    }
    
    void insert(int data){
        
        int index = data%arrSize;

        node* temp = arr[index];

        if(temp == NULL){
            arr[index] = new node(data);
        }

        else{
            node* prev = NULL;
            
            while(temp!=NULL && temp->data!=-1){
                totalInsertProbe++;
                prev = temp;
                temp = temp->next;
            }

            node* toInsert = new node(data);
            prev->next = toInsert;
        }

    }

    void del(int data){
        
        int index = data%arrSize;

        if(arr[index] == NULL){
            cout << "\n\nData is not Present\n\n";
        }
        else{

            node* temp = arr[index];
            node* prev = NULL;
            while(temp!=NULL && temp->data != data){
                prev = temp;
                temp = temp->next;
            }
            if(temp == NULL){
                cout << "\n\nData is not Present\n\n";
            }
            else{
                if(prev==NULL){
                    
                    arr[index] = arr[index]->next;
                    delete temp;
                }
                else{

                    prev->next = temp->next;
                    delete temp;
                }
            }
        }

    }

    void search(int data){
        int index = data % arrSize;
        if(arr[index] == NULL){
            cout << "\nData is not present" << endl;
        }
        else{

            node* temp = arr[index];
            while(temp!=NULL && temp->data !=data){
                totalSearchProbe++ ;
                temp = temp->next;
            }
            if(temp == NULL){
                
                cout << "\n----**** Data is not present ****----" << endl;
            }
            else{
                
                cout << "\n----**** Data is present ****---- " << endl;
            }
        }
    }

    void display(){
        
        for(int i=0;i<arrSize;i++)
        {
            node* var = arr[i];
            if(var!=NULL){
                cout<<i<<" : "<<var->data;
                while(var->next){
                    var=var->next;
                    cout<<" --> "<<var->data;
                }
                cout<<endl;
            }
        }
    }

    float averageInsertProbe(){
        float probe = totalInsertProbe;
        return probe/arrSize;
    }

    float averageSearchProbe(){
        float probe = totalSearchProbe;
        return probe/arrSize;
    }
};

void menu(){
    cout << "Enter 1 for insert data"<<endl;
    cout << "Enter 2 for delete" << endl;
    cout << "Enter 3 for search" <<endl;
    cout << "Enter 4 for display" <<endl;
    cout << "Enter 5 for Average Insert Probe" << endl;
    cout << "Enter 6 for Average Search Probe " << endl;
    cout << "Enter 0 for exit" << endl;
}

int main ()
{
    cout << "Enter the size of the hashmap : ";
    int hsize;
    cin >> hsize;

    hashmap h(hsize);
    menu();
    int choice=1;
    while (choice!=0)
    {
        cout<<"\nEnter your choice : ";
        cin>>choice;
        cout<<endl;
        if (choice==1)
        {
            int data ;
            cout<<"\nEnter Data : ";
            cin >> data;
            
            h.insert(data);
            
        }
        else if (choice==2)
        {
            int data ;
            cout<<"\nEnter Data : ";
            cin >> data;
            
            h.del(data);
            
        }
        else if (choice==3)
        {
            int data ;
            cout<<"\nEnter Data : ";
            cin >> data;
            
            h.search(data);
            
        }
        else if(choice==4){
            cout << endl;
            h.display();
            cout << endl;
        }
        else if (choice == 5){
            cout << endl;
            cout << "Average Insert Probe - " << h.averageInsertProbe()<<endl;
            cout <<endl;
        }
        else if (choice == 6){
            cout << endl;
            cout << "Average Search Probe - " << h.averageSearchProbe()<<endl;
            cout <<endl;
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