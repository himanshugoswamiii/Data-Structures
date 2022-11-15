#include <iostream>
#include <algorithm>
#include <type_traits>
using namespace std;

// Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void bubbleSort(int Arr[],int n){
    for (int i = 0; i < n-1 ; i++) {
        for (int j = 0; j < n-1-i; j++) {
            // We'll get max in last
            if (Arr[j]>Arr[j+1])
            {
                swap(Arr[j],Arr[j+1]);
            }
        }
    }
}
int main ()
{
    int Arr[]={21,3,-8,5,5,21,39};
    int len=sizeof(Arr)/sizeof(int);
    printArray(Arr,len);
    bubbleSort(Arr, len);
    printArray(Arr,len);

    return 0;
}

