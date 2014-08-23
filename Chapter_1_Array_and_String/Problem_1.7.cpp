#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;


//O(M*N) + O(1)
void setZeroes(vector<vector<int> > &matrix) {
	const size_t m = matrix.size();
	const size_t n = matrix.back().size();
	bool row = false;
	bool col = false;
	// process 1st col
	for (int i = 0; i < m;i++){
		if (matrix[i][0] == 0){
			col = true;
			break;
		}			
	}
	// process 1st row
	for (int j = 0; j < n; j++){
		if (matrix[0][j] == 0){
			row = true;
			break;
		}
	}
	// process others 
	for (int i = 1; i < m; i++){
		for (int j = 1; j < n; j++){
			if (matrix[i][j] == 0){
				matrix[0][j] = 0;
				matrix[i][0] = 0;
			}				
		}
	}
	// set 0 based on 1st row and col
	for (int i = 1; i < m; i++){
		for (int j = 1; j < n; j++){
			if (matrix[i][0] == 0 || matrix[0][j] == 0)
				matrix[i][j] = 0;
		}
	}
	// set 0 on 1st col
	if (col)
		for (int i = 0; i < m; i++)
			matrix[i][0] = 0;
	// set 0 on 1st row
	if (row)
		for (int j = 0; j < n; j++)
			matrix[0][j] = 0;
}


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
