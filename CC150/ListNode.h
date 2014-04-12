#include<iostream>
#include<vector>
using namespace std;

const int maxn = 100;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode{
	int key;
	TreeNode *left, *right, *parent;
};

class Solution {
public:
	TreeNode tree[maxn];
	TreeNode *p , *head ;
	ListNode* initList(int n, int a[]);
	ListNode* initList(vector<TreeNode*>vect, int cur, int last);
	ListNode* reverse(ListNode *head);

	void initTree();
	TreeNode *Solution::create_minimal_tree(TreeNode* &head, TreeNode *pp, int *a, int start, int end);
	void getDepth(TreeNode *head);
	int maxHeight();
	int printNodeAtLevel(TreeNode* &head, int level);
	void printNodeAtLevel(TreeNode* head);
	void printList(ListNode *head);
	
};