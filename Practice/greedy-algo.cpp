/*   The maximum number of meeting that i can do
    Time Complexity : 
    Space Complexity :  */
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pa;

bool cmp(pa A, pa B){
    return A.second < B.second;
}

int maxMeetings(vector<pa> &vals){
    int ans = 0;

    sort(vals.begin(), vals.end(), cmp);

    int ansEnd = vals[0].first;

    for (int i = 0; i < vals.size(); i++) {
        if (vals[i].first >= ansEnd)
        {
            cout << i << " ";
            ans++;
            ansEnd = vals[i].second;
        }
        
    }

    return ans;
}

int main ()
{
    vector<pa> vals = {{1, 3}, {3, 4}, {2, 5}, {4, 6}, {6, 7}, {5, 6}, {7, 8}};

    cout << maxMeetings(vals);
    
    return 0;
}
