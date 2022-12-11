#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void printArray(int Arr[], int len){
    for (int i = 0; i < len; i++) {
        cout << Arr[i] << ' ';
    }
    cout << endl;
}

void merge(int Arr[], int start, int mid, int end){
    int i = start;
    int j = mid+1;
    int k = 0;

    int Arr2[end-start+1]; // Auxillary array

    while (i <=mid && j <= end ){
        if (Arr[i] <= Arr[j])
        {
            Arr2[k] = Arr[i];
            i++;
        }
        else
        {
            Arr2[k] = Arr[j];
            j++;
        }

        k++;
    }

    while (i<=mid){
        // If left array is remaining
        Arr2[k]=Arr[i];
        i++;
        k++;
    }

    while (j<=end){
        // If right array is remaining
        Arr2[k]=Arr[j];
        j++;
        k++;
    }

    // Copy back to array Arr
    for (int i = start; i <= end; i++) {
        Arr[i] = Arr2[i-start];
    }

}

void mergeSort(int Arr[], int start, int end){
    if (start < end)
    {
        int mid = start + (end - start)/2;

        mergeSort(Arr, start, mid);
        mergeSort(Arr, mid+1, end);

        merge(Arr, start, mid, end);
    }
}

int main ()
{
    int Arr[] = {-89,2,-1,23,44,21,2,11};
    int len = sizeof(Arr)/sizeof(int);
    printArray(Arr, len);

    mergeSort(Arr, 0 , len-1);

    printArray(Arr, len);

    return 0;
}
