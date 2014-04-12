#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* initList(int n, int m, int a[]);

	ListNode* initList(int n, int a[]);
	/*Given a linked list, return the node where the cycle begins. */
	ListNode *detectCycle(ListNode *head);

	/*Sort a linked list using insertion sort.*/
	int sortArray(int a[], int n);

	ListNode *insertionSortList(ListNode *head);

	ListNode *insertionSortListRecur(ListNode *head);

	ListNode *insertionSortList_(ListNode *head);

	/*Given a singly linked list L: L0¡úL1¡ú¡­¡úLn-1¡úLn,
	reorder it to: L0¡úLn¡úL1¡úLn-1¡úL2¡úLn-2¡ú¡­
	You must do this in-place without altering the nodes' values.
	For example,Given {1,2,3,4}, reorder it to {1,4,2,3}.*/

	void reorderList(ListNode *head);

	//---------Reverse a linked list-------------
	ListNode *reverseBetween(ListNode *head, int m, int n);

	//-----print result----------------
	void printList(ListNode *head);

	//----delete all duplicates -------------------------
	ListNode *deleteDuplicates(ListNode *head);
	ListNode *deleteDuplicates_(ListNode *head);

	//---- duplicates are allowed at most twice----------
	int removeDuplicates(int A[], int n);
	int removeDuplicates_(int A[], int n);

};






