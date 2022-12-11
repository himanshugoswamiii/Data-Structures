#include "boilerplate.h"
#include <vector>

int partition(int Arr[], int start, int end){
    int pivot = Arr[end];
    int i = start-1;

    for (int j = start; j < end; j++) {
        if (Arr[j] <= pivot)
        {
            i++;
            std::swap(Arr[i], Arr[j]);
        }
    }
    std::swap(Arr[i+1], Arr[end]);
    return i+1;
}

void quickSort(int Arr[], int start, int end){
    if (start < end)
    {
        int pivot;

        pivot = partition(Arr, start, end);

        quickSort(Arr, start, pivot-1);
        quickSort(Arr, pivot+1, end);
        
    }

}


int main ()
{
    int Arr[] = {20,10,13,44,1,-8};
    int len = sizeof(Arr)/sizeof(int);


    printArray(Arr, 6);

    quickSort(Arr, 0, len-1);

    printArray(Arr, 6);



    return 0;
}
