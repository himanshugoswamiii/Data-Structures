#include <stdio.h>

void printArray(int* A,int n){
    for (int i = 0; i < n; i++) {
        printf("%d ",A[i]);
    }
    printf("\n");
}

// Partition
int partition(int A[],int low,int high){
    int pivot= A[low]; // Considering first element as pivot
    int i = low+1;
    int j = high;
    int temp; // Used for swapping

    do {

        while (A[i]<=pivot) {
            i++;
        }
        while (A[j]>pivot) {
            j--;
        }
        
        if(i<j){
            // Swapping when i<j
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
            
    } while(i<j);

    temp=A[low];
    A[low]=A[j];
    A[j]=temp;

    return j; // Returning index of pivot
}

void quickSort(int A[],int low, int high){
    int partitionIndex; // Index of pivot after partition
    
    if (low<high){
        partitionIndex = partition(A,low,high);
        quickSort(A,low,partitionIndex-1);
        quickSort(A,partitionIndex+1,high);
    }

}

int main ()
{
    // Array
    int A[]={3,5,2,13,12,12,2};
    int n=sizeof(A)/sizeof(int);
    printArray(A,n);
    quickSort(A, 0, n);
    printArray(A,n);
    
    return 0;
}
