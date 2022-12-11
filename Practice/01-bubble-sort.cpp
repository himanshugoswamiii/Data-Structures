#include <iostream>

using namespace std;

void printArr(int Arr[], int len){
	for (int i=0; i<len; i++){
		cout << Arr[i] << " ";
	}
	cout << endl;
}

void bubbleSort(int Arr[], int len){
	for (int i=0; i<len-1; i++){
		int flag = 0;
		for (int j=0; j<len-i-1; j++){
			if(Arr[j] > Arr[j+1]){
				swap(Arr[j], Arr[j+1]);
				flag = 1;
			}
		}
		if ( flag == 0){
			return;
		}
	}

}

int main(){
	int Arr[] = {3, 24, 2, 9, -7, 9, 1, 6};
	int len = sizeof(Arr)/sizeof(int);
	bubbleSort(Arr, len);

	printArr(Arr, len);
	return 0;
}
