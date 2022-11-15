#include <iostream>
#include <algorithm>
using namespace std;

// Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void bubbleSortModified(int Arr[],int n){
    bool swapped;
    for (int i = 0; i < n-1 ; i++) {
        swapped=false;
        for (int j = 0; j < n-1-i; j++) {
            if (Arr[j]>Arr[j+1])
            {
                swap(Arr[j],Arr[j+1]);
                swapped=true;
            }
        }
        if (swapped==false)
        {
            break;
        }
    }
}
int main ()
{
    int Arr[]={-8,3,5,5,21,39};
    int len=sizeof(Arr)/sizeof(int);
    printArray(Arr,len);
    bubbleSortModified(Arr, len);
    printArray(Arr,len);

    return 0;
}

