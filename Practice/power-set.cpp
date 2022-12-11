#include <iostream>
#include <vector>

using namespace std;

void powerSet(vector<int> &nums, vector<int> out, int index, vector<vector<int>> &ans){
	if ( index >= nums.size()){
		ans.push_back(out);
		return;
	}

	// Exclude
	powerSet(nums, out, index+1, ans);

	// Include
	int element = nums[index];
	out.push_back(element);
	powerSet(nums, out, index+1, ans);

}

int main(){
	vector<int> nums = {1, 2, 3, 4};
	vector<vector<int>> ans;
	vector<int> out;

	powerSet(nums, out, 0, ans);

	for (int i = 0; i<ans.size(); i++){
		for (int x : ans[i]){
			cout << x << " ";
		}
		cout << endl;
	}

	return 0;
}


