#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;



void setZeros(int a[][4], int m, int n){
	bool *row = new bool[m];
	bool *col = new bool[n];
	for (int i = 0; i < m; i++){
		cout << row[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < m; i++){
		cout << col[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (a[i][j] == 0)
			{
				row[i] = true;
				col[j] = true;
			}
		}
	}

	for (int i = 0; i < m; i++)
		cout << row[i] << " ";
	cout << endl;
	for (int i = 0; i < m; i++)
		cout << col[i]<< " ";
	cout << endl;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (row[i] == true || col[j] == true)
				a[i][j] = 0;
		}
	}

}




int main(){

	int a[][4] = {
			{ 1, 2, 3, 4 },
			{ 5, 6, 7, 8 },
			{ 9, 10, 0, 12 },
			{ 13, 14, 15, 16 }
	};
	setZeros(a,4,4);

	for (int i = 0; i < 4; i++){
		for (int b = 0; b < 4; b++)
			cout << a[i][b] << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}
