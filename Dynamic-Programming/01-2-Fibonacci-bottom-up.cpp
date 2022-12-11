/* Time Complexity : O(N)
    Space Complexity : O(N) */
#include <iostream>
#include <vector>
using namespace std;

int fib(int n){
    vector<int> memo(n+1);
    memo.at(0) = 0;
    memo.at(1) = 1;

    for (int i = 2; i < n+1; i++) {
        memo[i] = memo[i-1] + memo[i-2];
        
    }

    return memo[n];
}

int main ()
{
    int n;
    cin >> n;

    cout << fib(n) << endl;
    return 0;
}
