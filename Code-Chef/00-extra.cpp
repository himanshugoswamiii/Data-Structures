/*  Time Complexity : 
    Space Complexity :  */
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main ()
{
    int n;
    cin >> n;

    vector<int> Arr(n, 0);

    for (int x: Arr) {
        cout << x << " ";
        
    }

    cout << gcd(2, 4) << endl;

    return 0;
}
