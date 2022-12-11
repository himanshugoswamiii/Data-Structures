/*  Time Complexity : 
    Space Complexity :  */
#include <iostream>
#include <string>
using namespace std;

bool matchPattern(string str, string pattern){
    int n = str.length();
    int m = pattern.length();
    for (int i = 0; i < n-m; i++) {
        // n-m : because the remaining digits are less than the pattern
        int j;
        for (j = 0; j < m; j++) {
            if (str[i+j] != pattern[j])
            {
                break;
            }
        }

        if (j==m)
        {
            return true;
        }
    }
    return false;
}

int main ()
{
    string str = "What is your name";
    string pattern = "your";
    string pattern2 = "ok";
    cout << matchPattern(str, pattern) << endl;
    cout << matchPattern(str, pattern2) <<endl;
    return 0;
}
