#include <iostream>
#include <vector>
using namespace std;
class MyHashMap {
    public:
        vector<vector<pair<string,int>>>v;
         int ms=1000;
        
        MyHashMap() {
           v.clear();
           v.resize(1000);
        }
        
      
        void insert(string s, int value) {
            int key=hashcode(s);
            
            if(v[key%ms].size()==0)
            {
                v[key%ms].push_back({s,value});
            }
            else
            {
                bool flag=1;
                for(int i=0;i<v[key%ms].size();i++)
                {
                    if(v[key%ms][i].first==s)
                      {  
                        v[key%ms][i].second=value;
                        flag=0;
                      }
                }
                if(flag)
                {
                     v[key%ms].push_back({s,value});
                }
                
            }
            
        }
        
     
        int search(string s) {
            int key=hashcode(s);
            
            for(int i=0;i<v[key%ms].size();i++)
                {
                    if(v[key%ms][i].first==s)
                      {  
                         return v[key%ms][i].second; 
                      }
                }
            return -1;
        }
        
        
        void remove(string s) {
            int key=hashcode(s);
            for(int i=0;i<v[key%ms].size();i++)
                {
                    if(v[key%ms][i].first==s)
                      {  
                        v[key%ms].erase(v[key%ms].begin()+i); 
                      }
                }
        }

        /* void displayHash (){
            for(int i=0;i<v.size();i++)
              cout << v[i].first;
              cout << endl;
           }
        } */

        int hashcode(string key){
            int index=1;
            int code=0;
            for(char ch : key)
            {
                code+=(int(ch)+index+10);  // Conversion of String to the key
            }
            return code;
        }
};

void menu(){
    cout << "Enter 1 for insert data"<<endl;
    cout << "Enter 2 for delete" << endl;
    cout << "Enter 3 for search" <<endl;
    cout << "Enter 4 for display Map" << endl;
    cout << "Enter 0 for exit" << endl;
}//
int main ()
{
    MyHashMap h;
    int choice=1;
    while (choice!=0)
    {
        menu();
        cout<<"Enter your choice : ";
        cin>>choice;
        cout<<endl;
        switch (choice) {
            case 1:{
                string key;
                cout<<"\nEnter name of student : ";
                cin.ignore();
                getline(cin,key);
                float data;
                cout<<"\nEnter height of the student : ";
                cin>>data;
                h.insert(key,data);
                cout<<"\n\nData inserted with key - "<<key<<" and value - "<<data<<endl<<endl;
                break;
            }

            case 2:{
                string key;
                cout<<"\nEnter name of student : ";
                cin.ignore();
                getline(cin,key);
                h.remove(key);
                cout<<"\n\nData deleted with key - "<<key<<endl<<endl;
                break;
            }
            case 3:{
                string key;
                cout<<"\nEnter name of student : ";
                cin.ignore();
                getline(cin,key);
                float ans=h.search(key);
                if(ans==-1){
                    cout<<"\n\nInvalid Key\n\n"<<endl;
                }
                else{
                    cout<<"\n\nStudent's height - "<<ans<<endl<<endl;
                }
                break;
            }
            case 4:{
                cout << endl;
                h.displayHash();
                cout << endl;
                break;
            }
            case 0:
                break;

            default:
                cout<<endl<<"\nWrong input\n"<<endl;
                break;
        }
    }
    return 0;
}
