#include<iostream>
#include"leetCode.h"
using namespace std;

Solution sul;
//-----------main function-------------
void main(){
	//int a[] = { 3, 7, 4,9 ,5, 2, 6, 1  };
	int a[] = { 4,5};
	int n = 2, m = 1, c = 2;
	/*detect cycle in the list*/
	int value = sul.detectCycle(sul.initList(n, m, a))->val;
	cout << "The cycle begin with "
		<< value << endl;
	/*insert sort list*/
	cout << "The head of sorted list is "
		<< sul.insertionSortList_(sul.initList(n, a))->val << endl;

	//cout << "reversed list is: " << endl;
	//sul.reorderList(sul.initList(n, a));

	//--------Reverse a linked list from position m to c-----
	//sul.reverseBetween(sul.initList(n, a), m, c);
	cout << "reverse Between " << m <<" and "<< c << endl;
	sul.printList(sul.reverseBetween(sul.initList(n, a), m, c));
	
	
	system("pause");

}
