#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>


using std::sort;
using std::vector;
using std::pair ;
using std::cout;
using std::cin;
using std::endl;

void printVec(vector<pair<int, int>> vec){
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i].first << " ";
        cout << vec[i].second ;
        cout << endl;
    }
    cout << endl;
}

bool cmp(pair<int, int> A, pair<int, int> B){
    return A.second<B.second; 
}


int main ()
{
    vector<pair<int, int>> vec = {{1,2}, {6, 7}, {34, 2}, {1, 1}};

    printVec(vec);


    // sort(vec.begin(), vec.end());


    sort(vec.begin(), vec.end(), cmp);

    printVec(vec);

    


    
    return 0;
}
