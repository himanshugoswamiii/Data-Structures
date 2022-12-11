#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int main ()
{
    int n;
    cout << "Enter the no : ";
    cin >> n;
    for (int i = 1; i<= std::sqrt(n); i++) {
        if (n%i==0)
        {
            cout << i << endl;
        }
    }

    cout << n << endl;

    return 0;
}
