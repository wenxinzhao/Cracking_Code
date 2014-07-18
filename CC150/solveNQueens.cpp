#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<string> > vv;

vector<string> Result(int *arr, int n)
{
	vector<string> v;
    for (int i = 1; i != n + 1; ++i){		
		string s;
		for(int j = 1; j != n+1; ++j){
			if(j == arr[i])
				s += 'Q';
			else 
				s += '.';
		}
		v.push_back(s);
	}
	return v;
}
bool Verify(int *arr, int i)
{	
    for (int k = 1; k != i; ++k){
        if (arr[k] == arr[i] || abs(i - k) == abs(arr[i] - arr[k]))
			return false;           
	}
    return true;
}

void NQueens(int *arr, int i, int n)
{
    for (int j = 1; j != n + 1; ++j)
    {
        arr[i] = j;
        if (Verify(arr, i))
        {
            if (i == n)
				vv.push_back(Result(arr, n));       
            else
                NQueens(arr, i + 1, n);
        }
    }
}
 vector<vector<string> > solveNQueens(int n) {
    int *arr = new int[n + 1];	
    NQueens(arr, 1, n);
	return vv;
 }


int main()
{
    int n;
	solveNQueens(8);
    system("pause");
    return 0;
}
