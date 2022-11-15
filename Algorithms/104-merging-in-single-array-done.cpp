#include <iostream>

using std::cout;
using std::endl;

void merge(int A[], int low, int mid, int high){
    int i,j,k;
    int B[high+1]; // Extra array to store the values
    i=low;
    j= mid+1;
    k= 0;

    while (i <= mid && j <= high){
        if (A[i] <= A[j])
        {
            B[k]=A[i];
            i++;
            k++;
        }
        else
        {
            B[k]=A[j];
            j++;
            k++;
        }
        
    }

    while (i<=mid){
        B[k]=A[i];
        i++;
        k++;
    }

    while (j<=high){
        B[k]=A[j];
        j++;
        k++;
    }

    // Now B is the sorted array, copy sorted values back to A
    for (int z = 0; z <= high; z++) {
        A[z]=B[z];
    }
}

void printArr(int arr[], int len){
    for (int i = 0; i < len; i++) {
        cout << arr[i] << endl;
    }
}

int main ()
{
    int arr[] = {1,4,6,2,5,10,11,12};
    // Here 0:2 is one sorted array and 3: end is one sorted array

    int len = sizeof(arr)/sizeof(int);

    merge(arr,  0, 2, len-1);

    printArr(arr, len);
    return 0;
}
