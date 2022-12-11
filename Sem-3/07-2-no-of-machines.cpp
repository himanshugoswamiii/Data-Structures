#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
bool compare(pair<int, int> A, pair<int, int> B){
    return A.second<B.second;
}

int maxTask(vector<pair<int, int>> vec){

    int n = vec.size();
    sort(vec.begin(), vec.end(), compare);

    vector<int> done(n, 0);

    int completed = 0;

    int ansEnd, count = 1;
    while (!completed){
        for (int i = 0; i < n; i++) {
            if (done[i] == 0)
            {
                ansEnd = vec[i].second;
                break;
            }
        }
        for (int i = 1; i < n; i++) {
            if (done[i] == 0 && vec[i].first > ansEnd)
            {
                done[i] = 1;
                ansEnd = vec[i].second;
            }
        }

        count++;

        for (int i = 0; i < n; i++) {
            if (done[i] == 0)
            {
                completed = 0;
                break;
            }
            completed = 1;
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
