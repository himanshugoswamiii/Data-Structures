// Done using dp
#include <iostream>
#include <vector>

using namespace std;

int countDistinctWays(int nStairs, int i, vector<int> &memo){
    if (i > nStairs)
    {
        return 0;
    }

    if (i == nStairs)
    // When we've reached the final stair
    {
        return 1;
    }

    memo[i] = countDistinctWays(nStairs, i+1, memo) + countDistinctWays(nStairs, i+2, memo);

    return memo[i];

}

int main ()
{
    int nStairs;
    cin >> nStairs;
    vector<int> memo(nStairs+1, -1);
    cout << countDistinctWays(nStairs, 0, memo);

    return 0;
}
