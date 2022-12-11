#include <iostream>

using namespace std;

double pow(int x, int n){
	double ans = 1.0;
	if ( x==1 || n==0) return ans;

	while(n!=0){
		if(n%2 == 0){
			x = x*x;
			n = n/2;
		}
		else{
			ans *= x;
			n = n-1;
		}
	}

	return ans;
}



int main(){
	int T;
	cin >> T;

	int x, n;
	while(T--){
		cin >> x;
		cin >> n;
		cout << pow(x, n) << endl;
	}
	
	return 0;
}
