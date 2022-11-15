#include <iostream>
#include <utility>

using std::cout;
using std::endl;

int partition(int Arr[], int left, int right){
    /* Considering our pivot is right element */

    int i=left-1; //
    int pivot = Arr[right];
    for (int j = left; j < right; j++) {
        if (Arr[j]< pivot)
        {
            i++; // Maintain the order of these lines
            std::swap(Arr[i], Arr[j]);
        }
    }

    std::swap(Arr[i+1], Arr[right]);
    return i+1;
}

void quick_sort(int Arr[], int left, int right){
    if (left < right)
    {
        int part = partition(Arr, left, right);
        quick_sort(Arr, left, part-1);
        quick_sort(Arr, part+1, right);
    }
}

void printArr(int arr[], int len){
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout <<  endl;
}

int main ()
{
    int Arr[] = {2,3,9,-6,12,13};
    int len = sizeof(Arr)/sizeof(int);

    printArr(Arr, len);

    quick_sort(Arr, 0, len-1);

    printArr(Arr, len);

    return 0;
}
