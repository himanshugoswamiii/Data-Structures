#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
	priority_queue<int> max;
	max.push(20);
	max.push(30);
	max.push(10);
	max.push(-5);

	while(!max.empty()){
		cout << max.top() << " ";
		max.pop();
	}

	return 0;
	
}
