// Done
// Program with assumption : Input size in power of 2
// Modify for all odd inputs
#include <cmath>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::pow;


long karatsuba(int x, int y, int n){
    /*
    n : size of the number
    */
    if (n == 1) {
        return x*y;

    }
    int a1 = x / int(pow(10, n/2)); // quotient
    int a2 = x % int(pow(10, n/2)); // remainder

    int b1 = y / int(pow(10, n/2)); // quotient
    int b2 = y % int(pow(10, n/2)); // remainder

    long A = karatsuba(a1, b1, n/2);
    long B = karatsuba(a2, b2, n/2);
    long C = karatsuba(a1+a2, b1+b2, n/2);


    return (a1*b1)*pow(10,n) + (C-A-B)*int(pow(10,n/2)) + B;
}

int size(int x){
    if (x == 0)
    {
        return 1;
    }
    int count = 0;
    while (x!=0){
        count++;
        x = x/10;
    }

    return count;
}

int main ()
{
    int x, y, s, times;
    cout << "How many times ? " << endl;
    cin >> times;

    for (int i = 0; i < times; i++) {
        cout << "Enter your numbers : " << endl;
        cin >> x >> y;

        s = (x>y)?size(x):size(y); // Choose the biggest number to find the size

        cout << karatsuba(x, y, s) << endl;
    }

    return 0;
}
