#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
vector<int>mi,mj;

bool condition(int j,vector<int>mj ){
	while(!mj.empty()){
		if(j == mj.back()){
			return false;
			break;
		}
		mj.pop_back();
	}
	return true;

}
void add_element(int i,int jj, int n, int a[4][4]){
	int j;
	for(j = jj; j<n; j++){
		if( condition(j,mj) && (i+j != mi.back() + mj.back()) && ((i-j)!=(mi.back()-mj.back()) ) ) {
			a[i][j] = 1;
			mi.push_back (i);
			mj.push_back (j);
			break;
		}	
	}
	if(j == n){
			int mii = mi.back();
			mi.pop_back();
			int mjj = mj.back();
			mj.pop_back();
			a[mii][mjj] =0;
			add_element(i-1,mjj+1,n,a);
	}
	
	
	if(i == n-1)
		return;	
	add_element(i+1,0,n,a);
	
}

vector<vector<string> > solveNQueens(int n) {
      vector<vector<string> > v;
	  int a[4][4] = {NULL};
	  
	  mi.push_back (-10);
	  mj.push_back (-100);

	 // for(int i = 0; i<n;i++){
		  add_element(0,0,n,a);
	 // }

	return v;
}

//bool add_element(int j,int i, int a[4][4]){
//	if( condition(j,mj) && (i+j != mi.back() + mj.back()) && (abs(i-j)) != abs(mi.back()-mj.back())){
//		a[i][j] = 1;
//		mi.push_back (i);
//		mj.push_back (j);
//		//break;
//		return true;
//	}
//	return false;
//
//}


void main(){
	solveNQueens(4);
	system("pause");	
}
