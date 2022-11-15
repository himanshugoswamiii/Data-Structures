#include <iostream>
#include <vector>

using std::cout;
using std::endl;

void toAdjList(int (*Array)[4], int len){

    cout << *Array << endl;

    for (int x : *Array) {
        cout << x << " ";
    }
    cout << endl;
}

int main(){

	int matrix[][4] = {
		0, 1, 1, 0,
		1, 1, 1, 0,
		0, 0, 1, 1,
        1, 0, 1, 0 
    };

    toAdjList(matrix, 4);

    int rows = sizeof(matrix)/sizeof(matrix[1]);
    int columns = sizeof(matrix[1])/sizeof(int);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

	return 0;
}
