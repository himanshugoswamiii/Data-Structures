// completed
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

int quickSelect(int Arr[], int start, int end, int index){
    if(start == end){
        return Arr[start];
    }

    int pivot = partition(Arr, start, end);

    if (index == pivot){
        return Arr[index];
    }
    else if (index < pivot)
    {
        return quickSelect(Arr, start, pivot-1, index);
    }
    else
    {
        return quickSelect(Arr, pivot+1, end, index);
    }
}


int main ()
{
    int Arr[] = {20,10,13,44, 121,1,-8, 23, 45, 234};
    int len = sizeof(Arr)/sizeof(int);

    int index;

    printArray(Arr, len);
    cout << "Enter the kth index : " << endl;

    cin >> index;

    cout << "(k+1)th smallest element is : " << quickSelect(Arr, 0, len-1, index) << endl;

    // printArray(Arr, len);



    return 0;
}
