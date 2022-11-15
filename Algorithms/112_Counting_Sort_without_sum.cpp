#include <iostream>
using namespace std;
#define K 9 // Range 0-9
int main ()
{
    int Arr[]={1,4,1,2,7,5,2};

    // Range : 0-9
    int CountArr[K+1]={0}; // Initialize the array with 0 : O(k)

    // Sorted Array of the same length as Unsorted Arr
    int len=sizeof(Arr)/sizeof(int);
    int SArr[len];

    // Counting : O(n)
    for (int i = 0; i < len; i++) {
        CountArr[Arr[i]]+=1;
    }

    // Sum of counts : O(k) - Without this

    int j=0;
    // Creating Sorted Array : O(n^2) -- This changed because we didn't keep the sum
    for (int i = 0; i <= K; i++) {
        if (CountArr[i]>0)
        {
            while (CountArr[i]!=0)
            {
                SArr[j]=i;
                j++;
                --CountArr[i];
            }
            
        }
        
    }

    // Printing Sorted Array
    for (int k = 0; k < len; k++) {
        cout << SArr[k] << " ";
    }

    return 0;
}
