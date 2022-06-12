#include<iostream>
#include <list>
using namespace std;
struct Node{
    char name[20];
    int value;
};
class Hash{
   int BUCKET;
   list < Node >*table;
   public:
    // Constructor
   Hash (int V){
       this->BUCKET = V;
       table = new list < Node >[BUCKET]; // Create a new list of size bucket

    }
    void insertItem (int key,int data){
       int index = hashFunction (key);
       table[index].push_back ({key,data});
        //push_back() : Adds a new element at the end of the vector.
    }
   void deleteItem (int key){
       int index = hashFunction (key);
       list < int >::iterator i;
       for (i = table[index].begin (); i != table[index].end (); i++){
       if (*i == key)
          break;
       }
       if (i != table[index].end ())
          table[index].erase (i);
    }
    int hashFunction (int x){
        return (x % BUCKET);
    }
    void searchItem (int key){

    }
    void displayHash (){
       for (int i = 0; i < BUCKET; i++){
          cout << i;
          for (auto x:table[i]){
              cout << " --> " << x.name<<":"<<x.value;
            }
          cout << endl;
       }
    }
};

// Driver's Code
int main (){
   int a[] = { 5, 12, 67, 9, 16 };
   int n = 5;
   Hash h(10); // We're given to create a hash map of 10 elements
    string key;
    cout<<"\nEnter name of student : ";
    cin.ignore();
    getline(cin,key);
    float data;
    cout<<"\nEnter height of the student : ";
    cin>>data;
    h.insertItem(key,data);
    cout<<"\n\nData inserted with key - "<<key<<" and value - "<<data<<endl<<endl;
   h.deleteItem (12);
   h.displayHash ();
   return 0;
}
