/*  Time Complexity : O(N)
    Space Complexity : O(1) */
#include <iostream>

using namespace std;

int fib(int n){
    int prev1 = 1; // n-1
    int prev2 = 0; // n-2
    int curr; // current 

    // When n = 0
    if (n == 0){
        return 0;
    }

    for (int i = 2; i < n+1; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
        
    }

    return curr;
}

int main ()
{
    int n;
    cin >> n;

    cout << fib(n) << endl;
    return 0;
}

