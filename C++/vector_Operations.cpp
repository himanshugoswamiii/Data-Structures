#include <iostream>
#include <vector>
using namespace std;


// Function to print the vector
void printVec(vector <int> Vec){
    for (int i = 0; i < Vec.size(); i++) { 
        // size() : returns the no of elements in the vector
        cout << Vec[i]<<" ";
    }
    cout<<endl;
}

int main ()
{

    vector <int> Vec;
    Vec.push_back(10); // Inserting element in the vector
    Vec.push_back(20); // Inserting element in the vector
    Vec.push_back(30); // Inserting element in the vector

    printVec(Vec);

    // Accessing element of the vector : VecName.at(index)
    cout<<"\nThe second element is: "<<Vec.at(1); 
    // Acessing elements like an Array
    cout<<"\nThe third element is: "<<Vec[2]<<endl;


    // Changing vector Elements using at()
    Vec.at(0)=100; // change element at index 0 to 100
    Vec.at(2)=100; // change element at index 2 to 100
    printVec(Vec);


    // Deleting elements from Vector
    Vec.pop_back(); // NOTE: it doesn't return the popped value
    printVec(Vec);

    
    return 0;
}
