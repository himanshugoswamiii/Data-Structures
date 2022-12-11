#include <iostream>

using namespace std;

int main ()
{
    int Arr[] = {1, 2, 3};
    int n = sizeof(Arr)/sizeof(int);

    for (int i=0; i<n; i++) {
        cout << Arr[i]; 
        for (int j = 0; j < n; j++) {
            cout << Arr[j];
        }
    }
    
    return 0;
}
