#include <iostream>

using std::cout;
using std::endl;

void printArr(int arr[], int len){
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout <<  endl;
}

void merge(int A[], int low, int mid, int high){
    int i,j,k;
    int B[high-low+1]; // Extra array to store the values
    i = low;
    j = mid+1;
    k = 0;

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
    for (int z = low; z <= high; z++) {
        A[z]=B[z-low];
    }
}




void mergeSort(int arr[], int start, int end){

	if (start < end ){
        int mid = (start + end)/2;

        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);

        merge(arr, start, mid, end);
	}

}

int main ()
{
    int arr[] = {2,1,-8,5,1,2, 4};

    int length = sizeof(arr)/sizeof(int);

    cout << "Before Sorting : "; 
    printArr(arr,length);

    mergeSort(arr, 0, length-1);

    cout << "After Sorting : "; 
    printArr(arr,length);


    return 0;
}
