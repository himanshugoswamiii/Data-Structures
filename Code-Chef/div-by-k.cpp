#include <iostream>
#include <vector>
using namespace std;

int findSubset(vector<int> &nums, int prod, int index , int k, int n){
    if(prod % k == 0){
            return 1;
    }
    
    if(index >= n){
        
        return -1;
    }
    
    // Exclude
    int ans1 = findSubset(nums, prod, index+1, k, n);
    
    // Include
    prod *= nums[index];
    int ans2 = findSubset(nums, prod, index+1, k, n);
    
    if (ans1 == 1 || ans2 == 1)
    {
        return 1;
    }
    
    return -1;
    
}

int main() {
	int T;
	cin >> T;
	while(T--){
	    int n, k;

        cin >> n;
        cin >> k;

	    // n : size of array
	    // k ; 
	    vector<int> vec;
	    for (int i=0; i<n; i++){
	        int x;
	        cin >> x;
	        vec.push_back(x);
	    }
	    
        int z;
	    z = findSubset(vec, 1, 0, k, vec.size());
	    if (z == 1){
	        cout << "YES" << endl;
	    }
	    else{
	        cout << "NO" << endl;
	    }
	}

	return 0;
}
