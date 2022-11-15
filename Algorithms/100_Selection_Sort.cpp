// Done by me
#include <iostream>
#include <type_traits>
using namespace std;

void SelectionSort(int Arr[],int size,int start){
    if (start>=size)
    {
        // Exit condition
        return;
    }
    int min=Arr[start];
    int index=start;
    for (int i = start; i < size; i++) {
        if(min>Arr[i]){
            min=Arr[i];
            index=i; // Storing the index to swap
        }
    }
    swap(Arr[start],Arr[index]);
    SelectionSort(Arr, size, start+1);
}

int main ()
{
    int Arr[]={34,1,2,-9,23,6,1,1,-6,21};
    int size=sizeof(Arr)/sizeof(int);
    SelectionSort(Arr,size,0);

    // Printing the array -- Range based for loop
    for(int x : Arr){
        cout << x <<" ";
    }
    
    return 0;
}
