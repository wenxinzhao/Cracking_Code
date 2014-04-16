#include<iostream>
#include<vector>
using namespace std;

const int maxn = 100;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	//-----------parameter-------------------	
	TreeNode *p = NULL, *root = NULL;
	int i;

	/*--------------------------------------------------*/
	/*------------------Link List-----------------------*/
	/*--------------------------------------------------*/
	ListNode* initList(int n, int m, int a[]);

	ListNode* initList(int n, int a[]);
	/*Given a linked list, return the node where the cycle begins. */
	ListNode *detectCycle(ListNode *head);

	/*Sort a linked list using insertion sort.*/
	int sortArray(int a[], int n);

	ListNode *insertionSortList(ListNode *head);

	ListNode *insertionSortListRecur(ListNode *head);

	ListNode *insertionSortList_(ListNode *head);

	/*Given a singly linked list L: L0→L1→…→Ln-1→Ln,
	reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
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

	/*----------------------------------------------------*/
	/*------------------Binary Tree-----------------------*/
	/*----------------------------------------------------*/
	TreeNode* createTree(TreeNode* &head, TreeNode *pp, int *a, int start, int end);
	//--Binary Tree Level Order Traversal--
	vector<vector<int> > levelOrder(TreeNode *root);
	vector<vector<int> > levelOrderBottom(TreeNode *root);
};

