#include "stdio.h"
void printArray(int *Arr,int l){
    for(int i=0;i<l;i++){
        printf("%d\n",Arr[i]);
    }
}
void insertionSortAsc(int *Arr,int l){
    // Insertion Sort Ascending order
    int key,j;
    for(int i=1; i<=l-1; i++){
        key=Arr[i];
        j=i-1;
        while (j>=0 && Arr[j]>key) {
            Arr[j+1]=Arr[j];
            j--;

        }
        Arr[j+1]=key;
    }

}

void insertionSortDesc(int *Arr,int l){
    // Insertion Sort Descending order
    int key,j;
    for(int i=1; i<=l-1; i++){
        key=Arr[i];
        j=i-1;
        while (j>=0 && Arr[j]<key) {
            Arr[j+1]=Arr[j];
            j--;

        }
        Arr[j+1]=key;
    }

}
int main ()
{
    int Arr[]={11,15,8,6,16,19,20};
    int len=sizeof(Arr)/sizeof(int);

    printArray(Arr, len); // Printing Unsorted Array

    printf("\n Array after Ascending Sorting\n");
    insertionSortAsc(Arr,len); // Passing Arr and length of the array as argument
    printArray(Arr, len);

    printf("\n Array after Descending Sorting\n");
    insertionSortDesc(Arr, len);
    printArray(Arr, len);

    return 0;
}
