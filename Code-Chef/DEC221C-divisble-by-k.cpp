#include <iostream>
#include <vector>
using namespace std;

int minY(vector<int> &nums, int val){
    int ans=1;
    for(int i=0; i<nums.size(); i++){
        if((ans*nums[i]) % val == 0) continue;
        else{
            ans++;
            i=0;
        }
    }
    
    return ans;
    
    
}

int main() {
	int T;
	cin >> T;
	while(T--){
	    int N;
        cin >> N;
	    vector<int> nums;
	    for(int i=0; i<N; i++){
	        int x;
	        cin >> x;
	        nums.push_back(x);
	    }
	    
	    for(int i=0; i<N; i++){
	        cout << minY(nums, nums[i]) << " ";
	    }
	}
	return 0;
}
