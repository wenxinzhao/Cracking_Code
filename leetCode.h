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
	
	
};

