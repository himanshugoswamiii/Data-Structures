// Will this code work ? Why not
// Array always decay into pointers when we're describing them as perimeters
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void printArr(int Array[], int len){
    cout << *Array << endl;
}

int main ()
{
    int arr[] = {1,2,3,4};

    printArr(arr, 4);
    return 0;
}
