/*  Time Complexity : O(N^2)
    Space Complexity : O(N) : for recursive stack variables */
#include <iostream>
#include <type_traits>

using namespace std;

void printArray(int Arr[], int len){
    for (int i = 0; i < len; i++) {
        cout << Arr[i] << ' ';
    }
    cout << endl;
}

void bubbleSortRec(int Arr[], int start, int end){
    if (start >= end)
    {
        return;
    }

    bool swapped = false;

    for (int j = 0; j < end-start ; j++) {
        if (Arr[j] > Arr[j+1])
        {
            swap(Arr[j], Arr[j+1]);
            swapped = true;
        }
        
    }
    if (swapped == false)
    {
        return;
    }

    bubbleSortRec(Arr, start+1, end);

}

int main ()
{
	int Arr[] = {3, 24, 2, 9, -7, 9, 1, -89, 23, 6};
	int len = sizeof(Arr)/sizeof(int);
	bubbleSortRec(Arr, 0, len-1);

	printArray(Arr, len);
	return 0;
}
