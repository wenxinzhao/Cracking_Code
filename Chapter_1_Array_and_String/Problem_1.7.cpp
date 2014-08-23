#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

void setZeroes(vector<vector<int> > &matrix) {
	const size_t m = matrix.size();
	const size_t n = matrix.back().size();
    vector<bool> row(m, false); 
	vector<bool> col(n, false); 
	for (int i = 0; i < m;i++){
		for (int j = 0; j < n; j++){
			if (matrix[i][j] == 0)
				col[i] = row[j] = true;			
		}
	}
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (col[i] == true || row[j] == true)
				matrix[i][j] = 0;
		}
	}
}

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
