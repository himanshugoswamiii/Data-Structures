/*  Time Complexity : 
    Space Complexity :  */
#include <iostream>

using namespace std;

int fib(int n){
    int ans;

    int first = 0;
    int second = 1;

    if (n==0)
    {
        return 0;
    }

    int third;
    for (int i = 2; i <= n; i++) {
        third = first+second;
        first = second;
        second = third;
    }

    ans = third;

    return ans;
}

int main ()
{
    cout << fib(0) << endl;
    cout << fib(8) << " ";

    
    return 0;
}
