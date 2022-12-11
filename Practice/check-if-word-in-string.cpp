#include <iostream>
#include <string>

using namespace std;
int bruteForce(string str, string word){
	int n = str.length();
	int len = word.length();
	for (int j=0; j<len; j++){
		// For the word
		int flag = 0;
		int temp = j;
		for (int i=0; i<n; i++){
			if (str[i] != word[temp]){
				continue;
			}
			else{
				flag = 1;
				temp++;
			}

			if ( temp+1 == len && flag == 1){
				return i-(len-1);
			}
		}
	}
	return -1;
}

int main ()
{
	string str = "What do you mean";
	string word = "do";
	int len = str.length();
	int n = word.length();

	cout << len << endl;
	cout << n << endl;
	cout << str << endl;

	cout << bruteForce(str, word);


    
    return 0;
}
