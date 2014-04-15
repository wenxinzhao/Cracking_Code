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
	TreeNode *p = NULL, *head = NULL;
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
	TreeNode* common_ancestor(TreeNode *head, TreeNode* node1, TreeNode* node2);
	bool isIn(TreeNode *head, TreeNode* node);
	void postOrder(TreeNode* head); 
	void inOrder(TreeNode* head);
	void preOrder(TreeNode* head);
	void find_sum(TreeNode* head, int sum);
	TreeNode* minimal(TreeNode *node);
	TreeNode* successor(TreeNode *node);
	bool identical_subtree(TreeNode *head1, TreeNode *head2);
	TreeNode* searchIn(TreeNode *head, TreeNode* node);
	bool matchTree(TreeNode* nd, TreeNode* node);
};
