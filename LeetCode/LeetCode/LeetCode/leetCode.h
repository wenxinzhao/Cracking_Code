#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
using namespace std;
//#define max(a, b)  (((a) > (b)) ? (a) : (b))
#define min(a, b)	(a < b ? a : b)
//#define max3(a, b,c)  (a>b ? (a>c ? a : c) : (b>c ? b : c))

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

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}	
};


class Solution {
public:
	//-----------parameter-------------------	
	TreeNode *p , *root ;
	int i;
	int iter;
	Solution(){
		iter = 0;
		p = NULL;
		root = NULL;
	}

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
	/*Binary Tree Preorder Traversal */
	vector<int> preorderTraversal(TreeNode *root);
	/*Postorder Traversal */
	vector<int> postorderTraversal(TreeNode *root);
	/*print path*/
	void calPath(TreeNode *root);
	void printVec(vector<TreeNode*> vec);

	/*Binary Tree Maximum Path Sum*/
	int maxPathSum(TreeNode *root);
	int findMaxSum(TreeNode* root, int& max_sum);
	int max(int a, int b);
	int max3(int a, int b,int c);
	TreeNode* CreateBitree(TreeNode *pNode, int *a); //level order create tree

	int pathAmplitude(TreeNode *root);
	int findAmplitude(TreeNode* root, int& path);
	int calcAbs(int a, int b, int c);
	int calcAbs(int a, int b);


	int maxProfit1(vector<int> &prices);
	int maxProfit2(vector<int> &prices); 
	int maxProfit3(vector<int> &prices);

	int singleNumber(int A[], int n);
	int singleNumber2(int A[], int n);
	int maxDepth(TreeNode *root);


	bool isSameTree(TreeNode *p, TreeNode *q);
	int reverse(int x);
	int numTrees(int n);
	vector<int> inorderTraversal(TreeNode *root);
	int searchInsert(int A[], int n, int target);
	TreeLinkNode *createLinkTree(TreeLinkNode* &head, TreeLinkNode *pp, int *a, int start, int end);
	TreeLinkNode *connect(TreeLinkNode *root);
	void *connect_recur(TreeLinkNode *root);

	int romanToInt(string s);
	string intToRoman(int num);
	int digit(char s);
	int maxSubArray(int A[], int n);
	int maxArray(int A[], int start, int end, int n);
};

void show_result(vector<int>nums);
void print(int i);
int combinate(int n, int m);
int permutate(int n, int m);
unsigned long long fac(int n);
int climbStairs(int n);
int removeElement(int A[], int n, int elem);

void NQueens(int *arr, int i, int n);
vector<vector<string> > solveNQueens(int n);
bool verify( int *arr, int i);
vector<string> getResult(int *arr, int n);
void inorderRecurTraverse( TreeNode *root );
bool isBalanced(TreeNode *root);
int getHeight(TreeNode *root, bool isBalanced);
