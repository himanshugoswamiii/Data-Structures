// Completed
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;


void printArray(int Arr[], int len){
    for (int i = 0; i < len; i++) {
        cout << Arr[i] << ' ';
    }
    cout << endl;
}

void merge(int Arr[], int start, int mid1, int mid2, int end){
    int i = start;
    int j = mid1+1;
    int k = mid2+1;
    int z = 0;

    int Arr2[end-start+1]; // Auxillary array

    while (i <=mid1 && j <= mid2 && k <= end ){
        // All 3 running together
        if (Arr[i] <= Arr[j] && Arr[i] <= Arr[k])
        // First sub-array
        {
            Arr2[z] = Arr[i];
            i++;
        }
        else if (Arr[j] <= Arr[i] && Arr[j] <= Arr[k])
        {
            Arr2[z] = Arr[j];
            j++;
            
        }
        else
        {
            Arr2[z] = Arr[k];
            k++;
        }

        z++;
    }

    // When first and second are running together

    while (i<=mid1 && j<=mid2) {
        if(Arr[i] <= Arr[j]){
            Arr2[z] = Arr[i];
            i++;
        }
        else{
            Arr2[z] = Arr[j];
            j++;
        }

        z++;
    }


    // When second and third are running
    while (j<=mid2 && k<=end){
        if (Arr[j] <= Arr[k])
        {
            Arr2[z] = Arr[j];
            j++;
        }
        else
        {
            Arr2[z] = Arr[k];
            k++;
        }
        z++;
    }

    // When first and third are remaining
    while (i<=mid1 && k<=end){
        if (Arr[i] <= Arr[k])
        {
            Arr2[z] = Arr[i];
            i++;
        }
        else
        {
            Arr2[z] = Arr[k];
            k++;
        }
        z++;
    }

    while (i<=mid1){
        // If left array is remaining
        Arr2[z++]=Arr[i++];
    }

    while (j<=mid2){
        // If second array is remaining
        Arr2[z++]=Arr[j++];
    }

    while (k<=end){
        // If second array is remaining
        Arr2[z++]=Arr[k++];
    }

    // Copy back to array Arr
    for (int i = start; i <= end; i++) {
        Arr[i] = Arr2[i-start];
    }

}

void mergeSort(int Arr[], int start, int end){
    // start : first index
    // end : last index
    if (end-start < 1)
    {
        return;
    }

    int mid1 = start + ((end - start)/3);
    int mid2 = start + 2*((end - start)/3) +1 ;

    mergeSort(Arr, start, mid1);
    mergeSort(Arr, mid1+1, mid2);
    mergeSort(Arr, mid2+1, end);

    merge(Arr, start, mid1, mid2, end);

}

int main ()
{
    //int Arr[] = {-89,2,-1,23,44,21,2,11, 23, 45, 63};
    int Arr[] = {283, 305, 527, 749, 961, 325, 356};
    int len = sizeof(Arr)/sizeof(int);
    printArray(Arr, len);

    mergeSort(Arr, 0 , len-1);

    printArray(Arr, len);

    return 0;
}
