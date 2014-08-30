#include <iostream>
using namespace std;

int row = 0, col = 4;
int search(int a[][5], int x, int m, int n){	
	while (row < m && col > 0){
		if (a[row][col] == x) return x;
		else if (a[row][col] < x) row++;
		else col--;
	}
}
int main(){
	int a[5][5];
	int v = 3;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++){
			a[i][j] = v;
			v++;
		}
	search(a, 15, 5, 5);
	cout << row << " " << col << endl;
	system("pause");
	return 0;
}
