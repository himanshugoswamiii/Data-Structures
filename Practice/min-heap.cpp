#include <iostream>
#include <queue>

using namespace std;

int main(){
	priority_queue<int, vector<int>, greater<int>> mini;

    vector<int> vec;
    vec.push_back(10);

	mini.push(10);
	mini.push(-5);
	mini.push(50);
	mini.push(5);

	while(!mini.empty()){
		cout << mini.top() << " ";
		mini.pop();
	}

	return 0;
}
