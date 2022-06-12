#include<iostream>
#include <list>
using namespace std;
class Hash{
   int BUCKET;
   list < int >*table;
   public:
    // Constructor
   Hash (int V){
       this->BUCKET = V;
       table = new list < int >[BUCKET]; // Create a new list of size bucket

    }
    void insertItem (int key){
       int index = hashFunction (key);
       table[index].push_back (key);
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
    void displayHash (){
       for (int i = 0; i < BUCKET; i++){
          cout << i;
          for (auto x:table[i]){
              cout << " --> " << x;
            }
          cout << endl;
       }
    }
};

// Driver's Code
int main (){
   int a[] = { 5, 12, 67, 9, 16 };
   int n = 5;
   Hash h(7);
   for (int i = 0; i < n; i++){
       h.insertItem (a[i]);
    }
   h.deleteItem (12);
   h.displayHash ();
   return 0;
}
