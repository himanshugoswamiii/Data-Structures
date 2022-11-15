// This is a STABLE Sorting
#include <iostream>
using namespace std;
#define K 9 // Range 0-9
int main ()
{
    int Arr[]={1,4,1,2,7,5,2};

    // Range : 0-9
    // Why didn't we declare K as variable: because it's giving ERROR
    int CountArr[K+1]={0}; // Initialize the array with 0 : O(k)

    // Sorted Array of the same length as Unsorted Arr
    int len=sizeof(Arr)/sizeof(int);
    int SArr[len];

    // Counting : O(n)
    for (int i = 0; i < len; i++) {
        CountArr[Arr[i]]+=1;
    }

    // Sum of counts : O(k)
    for (int i = 1; i < K; i++) {
        CountArr[i]+=CountArr[i-1];
    }

    // Creating Sorted Array : O(n)
    for (int j = len-1; j >= 0; j--) {
        // SArr[CountArr[Arr[j]]-1]=Arr[j];
        // --CountArr[Arr[j]]; 
        // or better way would be :
        --CountArr[Arr[j]]; 
        SArr[CountArr[Arr[j]]]=Arr[j];

    }

    // Printing Sorted Array
    for (int k = 0; k < len; k++) {
        cout << SArr[k] << " ";
    }

    return 0;
}
