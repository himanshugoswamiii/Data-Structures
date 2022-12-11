#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::cin;

void printArray(int Arr[], int len){
    for (int i = 0; i < len; i++) {
        cout << Arr[i] << ' ';
    }
    cout << endl;
}

void printVector(vector<int> vec){
    for (int x : vec) {
        cout << x << " ";
    }

    cout << endl;
}

