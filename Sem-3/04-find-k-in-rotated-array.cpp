// Done
#include <iostream>

using std::cout;
using std::endl;

int find_k(int Arr[], int size){
    for (int i = 0; i < size; i++) {
        if (Arr[i]>Arr[i+1]){
            return i+1;
        }
    }

    return -1;
}

int main ()
{
    int Arr[] = {36,41,7,18,29,31};
    int Arr2[] = {29,31,36,41,7,18};
    int len = sizeof(Arr)/sizeof(int);
    int len2 = sizeof(Arr2)/sizeof(int);

    cout << "k1 = " << find_k(Arr, len) << endl;
    cout << "k2 = " << find_k(Arr2, len2) << endl;
    return 0;
}
