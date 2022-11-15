#include <iostream>

using std::cout;
using std::endl;

void merge(int arr1[], int arr2[], int arr[], int len1, int len2, int len){
    int i = 0;
    int j = 0;
    int k = 0; 
    while (k < len){
        if (i < len1 && j < len2){
            // both of them working together
            if (arr1[i] <= arr2[j])
            {
                arr[k] = arr1[i];
                i++;
                k++;
            }
            else
            {
                arr[k] = arr2[j];
                j++;
                k++;
            }

        }
        else if (i < len1 && j >= len2)
        {
            // j finished before i
            arr[k] = arr1[i];
            i++;
            k++;
        }
        else
        {
            // If i finished before j
            arr[k] = arr2[j];
            j++;
            k++;
        
        }
    }
}

void printArr(int arr[], int len){
    for (int i = 0; i < len; i++) {
        cout << arr[i] << endl;
    }
}

int main ()
{
    int arr1[] = {1, 4, 6, 10}; 
    int arr2[] = {2, 6, 9, 11, 20, 21, 23, 44};

    int len1 = sizeof(arr1)/sizeof(int);
    int len2 = sizeof(arr2)/sizeof(int);

    int len = len1 + len2;

    int arr3[len];

    merge(arr1, arr2, arr3, len1, len2, len);

    printArr(arr3, len);


    return 0;
}
