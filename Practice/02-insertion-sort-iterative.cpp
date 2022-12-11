/*  Time Complexity : O(N^2)
    Space Complexity : O(1) */

#include <iostream>
#include <type_traits>

using namespace std;

void printArray(int Arr[], int len){
    for (int i = 0; i < len; i++) {
        cout << Arr[i] << ' ';
    }
    cout << endl;
}

void insSort(int Arr[], int len){
    for (int i = 1; i < len; i++) {
        // i : position of element we want to put in our sorted array

        int j = i;
        int key = Arr[i];

        while (key < Arr[j-1] && j>0){
            Arr[j] = Arr[j-1];
            j--;
        }

        Arr[j] = key;

    }
}

int main ()
{
	int Arr[] = {3, 24, 2, 9, -7, 9, 1, -89, 23, 6};
	int len = sizeof(Arr)/sizeof(int);

    insSort(Arr, len);

    printArray(Arr, len);
    return 0;
}
