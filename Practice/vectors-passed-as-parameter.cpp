#include <iostream>
#include <vector>
using std::cout;
using std::endl;

void func(std::vector<int> &myvec){
    for (int x : myvec) {
        cout << x << " ";
    }
    cout << endl;


    myvec.at(2) = 20;

    for (int x : myvec) {
        cout << x << " ";
    }
    cout << endl;
}

int main ()
{
    std::vector<int> vec = {20,30,40,50};

    func(vec);

    cout << "Call by Value : ";
    for (int x : vec) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
