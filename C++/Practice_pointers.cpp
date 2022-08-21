#include <iostream>
using namespace std;

int main ()
{
    int* x,y,z; // Here y and z are int
    int *a,*b,*c;
    cout << typeid(x).name() << endl; // Pointer Integer
    cout << typeid(y).name() << endl; // Integer
    cout << typeid(z).name() << endl;

    // Second notation
    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;
    cout << typeid(c).name() << endl;
    return 0;
}
