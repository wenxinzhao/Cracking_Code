#include <iostream>
#include <algorithm>
using namespace std;
struct person{
	int h;
	int w;
};
bool comp(person a, person b){
	if(a.h == b.h) 
		return a.w < b.w;
	else
		return a.h< b.h;

}
int LIS(person A[], int n){
    int *d = new int[n];
    int len = 1;
    for(int i=0; i<n; ++i){
        d[i] = 1;
        for(int j=0; j<i; ++j)
            if( A[j].w <= A[i].w && d[j]+1>d[i] )
                d[i] = d[j] + 1;
        if(d[i]>len) len = d[i];
    }
    delete[] d;
    return len;
}

int lis(int A[], int n){
    int *d = new int[n];
    int len = 1;
    for(int i=0; i<n; ++i){
        d[i] = 1;
        for(int j=0; j<i; ++j)
            if(A[j]<=A[i] && d[j]+1>d[i])
                d[i] = d[j] + 1;
        if(d[i]>len) 
			len = d[i];
    }
    delete[] d;
    return len;
}

int main(){
	person p[] = {{65, 100},{70, 80},{56, 90},{75, 190},{60, 95},{68, 110}};
	sort(p , p+6, comp);
	cout << LIS(p,6) << endl;
	int A[] = {
        5, 3, 4, 8, 6, 7
    };
    cout<<lis(A, 6)<<endl;
	system("pause");
	return 0;

}
