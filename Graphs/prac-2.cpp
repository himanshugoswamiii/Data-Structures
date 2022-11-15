#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

int main ()
{
    int x;
    cin >> x;
    int arr[x];

    for (int i = 0 ; i < 5 ; i++){
        cout<< arr[i] << " ";
    }
    cout << endl;

    std::vector<int> vec(x);

    for (int i = 0 ; i < 5 ; i++){
        cout<< vec[i] << " ";
    }

    return 0;
}
