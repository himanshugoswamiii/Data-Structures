#include <iostream>
#include <vector>

using namespace std;

// Function to print the vector
void printVec(vector <int> Vec){
    for (int i = 0; i < Vec.size(); i++) { 
        // size() : returns the no of elements in the vector
        cout << Vec[i]<<" ";
        
    }
}

// Driver Code
int main ()
{
    vector <int> myVec={1,3,5,7};  // Initializing a vector
    printVec(myVec);
    return 0;
}
