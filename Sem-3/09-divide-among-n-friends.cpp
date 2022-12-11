/*  Time Complexity : 
    Space Complexity :  */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void algo(vector<int> items,int n){
    sort(items.begin(), items.end());

    int sz = items.size();
    for (int i = 0; i < sz/2 ; i++) {
        cout << items[i] << " and " << items[sz-i-1] << endl;
    }

}

int main ()
{
    int c; // Constant
    cout << "Enter Constant : ";
    cin >> c;

    int n;
    cout << "Enter n : ";
    cin >> n;
    vector<int> set(2*n);

    cout << "Enter " << 2*n << " values" << endl;
    int val;
    for (int i = 0; i < 2*n; i++) {
        cin >> val;
        set.at(i) = val;
    }

    algo(set, n);

    return 0;
}
