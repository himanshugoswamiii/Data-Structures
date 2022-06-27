#include "stdio.h"
void printArray(int *Arr,int l){
    for(int i=0;i<l;i++){
        printf("%d ",Arr[i]);
    }
    printf("\n");
}
void insertionSortAsc(int *Arr,int l){
    // Insertion Sort Ascending order
    int iterations=0;
    int key,j;
    for(int i=1; i<l; i++){
        key=Arr[i];
        j=i-1;
        iterations++;
        while (j>=0 && Arr[j]>key) {
            Arr[j+1]=Arr[j];
            j--;
            iterations++;

        }
        Arr[j+1]=key;
    }
    printf("Insertion sort runs : %d\n",iterations);

}

int main (int argc, char *argv[])
{
    int myArr[]={2,1,2,1,2,1,2,1};
    printArray(myArr,8);
    insertionSortAsc(myArr,8);
    printArray(myArr,8);

    printf("\n");
    int myArr2[]={2,2,2,2,1,1,1,1};
    printArray(myArr2,8);
    insertionSortAsc(myArr2,8);
    printArray(myArr2,8);
    printf("\n");

    int myArr3[]={2,2,1,1,2,2,1,1};
    printArray(myArr3,8);
    insertionSortAsc(myArr3,8);
    printArray(myArr3,8);

    printf("\n");

    int myArr4[]={1,1,1,1,2,2,2,2};
    printArray(myArr4,8);
    insertionSortAsc(myArr4,8);
    printArray(myArr4,8);

    return 0;
}


