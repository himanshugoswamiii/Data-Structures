#include <iostream>
#include <vector>

using namespace std;

void permute(int nums[], vector<int> &ds, vector<int> &freq, int n){
	if (ds.size() == n){
		// Print the values
		for (int i=0; i<n; i++){
			cout << ds.at(i) << " ";
		}
		cout << endl;
		return;
	}

	for (int i=0; i<n; i++){
		if(freq[i] == 0){
			ds.push_back(nums[i]);
			freq[i] = 1;
			permute(nums, ds, freq, n);
			freq[i] = 0;
			ds.pop_back();
		}
	}
}

int main ()
{

	int Arr[] = {1, 2, 3, 5};

	int n = sizeof(Arr)/sizeof(int);

	vector<int> ds; // data-structure that will contain a permutation
	vector<int> freq(n, 0); // used for checking if an element has been visited

	permute(Arr, ds, freq, n);

    return 0;
}
