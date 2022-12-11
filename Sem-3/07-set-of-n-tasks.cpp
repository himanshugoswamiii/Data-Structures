// Completed
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
bool compare(pair<int, int> A, pair<int, int> B){
    return A.second<B.second;
}

int maxTask(vector<pair<int, int>> vec){

    sort(vec.begin(), vec.end(), compare);

    int ansEnd = vec[0].second;

    int count = 1;
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i].first > ansEnd)
        {
            count++;
            ansEnd = vec[i].second;
        }
    }



    return count;
}

int main ()
{
    // vector<pair<int, int>> time = {{1,2}, {3,4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};
    vector<pair<int, int>> time = {{1, 5}, {2, 4}, {3, 4}, {4, 5}, {3, 5}};

    cout << "Max tasks that can be done : " << maxTask(time) << endl;


    return 0;
}
