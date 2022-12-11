/*  Time Complexity : 
    Space Complexity :  */
#include <iostream>

using namespace std;

int countDistinctWays(int nStairs, int i){
    if (i > nStairs)
    {
        return 0;
    }

    if (i == nStairs)
    // How many ways can we reach the stair we are standing on
    {
        return 1;
    }

    return countDistinctWays(nStairs, i+1) + countDistinctWays(nStairs, i+2);

}

int main ()
{
    int nStairs;
    cin >> nStairs;
    cout << countDistinctWays(nStairs, 0);

    return 0;
}
