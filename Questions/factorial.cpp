/*  Time Complexity :  O(N)
    Space Complexity :  */
#include <iostream>
#include <vector>
using namespace std;

int factorial(int n, vector<int> &memo){
    if (n == 1)
    {
        memo[1] = 1;
        return 1;
    }

    memo[n] = n * factorial(n-1, memo);

    return memo[n];

}

int main ()
{
    int n;
    cin >> n;

    vector<int> vec(n+1, -1);

    factorial(n, vec);

    for (int i = 1; i <= n; i++) {
        cout << vec.at(i) << endl;
    }
    
    return 0;
}
