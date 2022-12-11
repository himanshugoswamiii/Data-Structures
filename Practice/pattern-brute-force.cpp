/*  What is the difference between strlen vs length function
    Space Complexity :  */
#include <iostream>
#include <cstring>

using namespace std;

bool checkPattern(string str, string pattern){
	int m = pattern.length();
	for (int i=0; i<str.length(); i++){
		int j;
		for (j=0; j<m; j++){
			if (pattern[j] != str[i+j]){
				break;
			}
		}
		if(j==m){
			return true;
		}
	}

	return false;
}

int main ()
{
	string str = "aaaaababaa";
	string pattern = "abab";
	string pattern2 = "abbb";

	cout << checkPattern(str, pattern) << endl;
	cout << checkPattern(str, pattern2);

    
    return 0;
}
