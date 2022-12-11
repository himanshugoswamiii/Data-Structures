/* Time Complexity : O(N) 
    Space Complexity : O(N) + O(N)
*/
#include <iostream>
#include <vector>
using namespace std;

int fib(int n, vector<int> &memo){
    // 1 : Base case
    if (n <= 1)
    {
        return n;
    }

    // 2 : Answer Available
    if (memo[n]!=-1)
    {
        return memo[n];
    }

    memo[n] = fib(n-1, memo) + fib(n-2, memo);

    return memo[n];

}

int main ()
{
    int n;
    cin >> n;

    vector<int> memo(n+1, -1);
    // Initialize vector with -1
    cout << fib(n, memo) << endl;
    return 0;
}
