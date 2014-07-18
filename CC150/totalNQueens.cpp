#include <iostream>
#include <string>
#include <vector>
using namespace std;

int count = 0;

bool Verify(int *arr, int i)
{
    for (int k = 1; k != i; ++k)
        if (arr[k] == arr[i] || abs(i - k) == abs(arr[i] - arr[k]))
            return false;
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
                count++;
            else
                NQueens(arr, i + 1, n);
        }
    }
}
 int totalNQueens(int n) {
	vector<vector<string> > vv;
    int *arr = new int[n + 1];	
    NQueens(arr, 1, n);
	return count;
 }


int main()
{
    int n;
	cout<< totalNQueens(8) <<endl;
    system("pause");
    return 0;
}
