#include<iostream>
#include"leetCode.h"
using namespace std;

Solution sul;
//-----------main function-------------
void main(){
	//int a[] = { 3, 7, 4,9 ,5, 2, 6, 1  };
	int a[] = { 1, 2,3,3,4,4,5};
	int n = 7, m = 1, c = 2;
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

	//----delete all duplicates -------------------------
	cout << "delete duplicates II...." << endl;
	sul.printList(sul.deleteDuplicates_(sul.initList(n, a)));
	
	//---- duplicates are allowed at most twice----------
	cout << "delete duplicates more than twice number...." << endl;
	n = sul.removeDuplicates(a, n);
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	cout << endl;


	system("pause");

}
