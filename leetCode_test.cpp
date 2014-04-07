#include<iostream>
#include"leetCode.h"
using namespace std;

Solution sul;
//-----------main function-------------
void main(){
	int a[] = { 3, 7, 4 ,9 ,5, 2, 6 ,1 };
	int n = 8, m = 2;
	/*detect cycle in the list*/
	int value = sul.detectCycle(sul.initList(n, m, a))->val;
	cout <<"The cycle begin with " 
		 << value << endl;
	/*insert sort list*/
	cout << "The head of sorted list is " 
		<< sul.insertionSortList_(sul.initList(n, a))->val << endl;

	system("pause");

}
