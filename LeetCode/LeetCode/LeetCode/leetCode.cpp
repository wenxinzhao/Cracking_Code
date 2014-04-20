#include"leetCode.h"
#include"bitmap.h"

int cnt;
int d = 0, depth[maxn], num = 0;


//----list initialization 1-------------
ListNode *Solution::initList(int n, int m, int a[]){
	ListNode *head = NULL, *p = NULL, *q = NULL;
	for (int i = 0; i < n; i++){
		ListNode *nd = new ListNode(a[i]);
		if (i == m) q = nd;
		if (i == 0){
			head = p = nd;
			continue;
		}
		p->next = nd;
		p = nd;
	}
	p->next = q;
	return head;
}
//----list initialization 2-------------
ListNode *Solution::initList(int n, int a[]){
	ListNode *head = NULL, *p = NULL, *q = NULL;
	for (int i = 0; i < n; i++){
		ListNode *nd = new ListNode(a[i]);

		if (i == 0){
			head = p = nd;
			continue;
		}
		p->next = nd;
		p = nd;
	}
	return head;
}
//---------sub function---------------
ListNode *Solution::detectCycle(ListNode *head) {
	if (head == NULL)
		return NULL;
	int count = 10000;
	ListNode *fast = head, *slow = head;

	while (count != 0){
		if (slow == NULL)
			return NULL;
		else
			slow = slow->next;
		if (fast->next == NULL || fast->next->next == NULL)
			return NULL;
		else
			fast = fast->next->next;
		if (slow == fast)
		{
			break;
		}
		else count--;
		if (count == 0)
			return NULL;
	}
	slow = head;
	while (slow != fast){
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
//-----------insertion sort------------
int Solution::sortArray(int a[], int n){
	int j;
	for (int i = 0; i < n; i++){
		int x = a[i];
		j = i;
		while (j>1 && a[j - 1] > x){
			a[j] = a[j - 1];
			j--;
		}
		a[j] = x;

	}
	return a[n - 1];

}

ListNode *Solution::insertionSortList(ListNode *head) {
	if (head == NULL)
	{
		return NULL;
	}
	else
	{
		ListNode* cur = head->next;
		head->next = NULL;
		while (cur != NULL)
		{
			ListNode* p = head;
			if (cur->val < p->val)
			{
				head = cur;
				cur = cur->next;
				head->next = p;
			}
			else
			{
				while (p != NULL)
				{
					if (p->next == NULL)
					{
						p->next = cur;
						cur = cur->next;
						p->next->next = NULL;
						break;
					}
					else
					{
						if (cur->val < p->next->val)
						{
							ListNode* tmp = p->next;
							p->next = cur;
							cur = cur->next;
							p->next->next = tmp;
							break;
						}
						p = p->next;
					}
				}
			}
		}
		return head;
	}
}
//-----------recursive insertion sort------------
ListNode *Solution::insertionSortListRecur(ListNode *head) {
	if (head == NULL || head->next == NULL){
		return head;
	}
	ListNode *nextHead = insertionSortList(head->next);
	if (head->val < nextHead->val){
		head->next = nextHead;
		return head;
	}
	else{
		ListNode *prev = nextHead;
		while (prev->next != NULL){
			if (head->val < prev->next->val){
				head->next = prev->next;
				prev->next = head;
				return nextHead;
			}
			prev = prev->next;
		}
		prev->next = head;
		head->next = NULL;
		return nextHead;
	}
}

ListNode *Solution::insertionSortList_(ListNode *head){
	if (head == NULL || head->next == NULL)
		return head;

	ListNode  * head1 = NULL;
	while (head != NULL) {
		ListNode  * current = head;
		head = head->next;
		if (head1 == NULL || current->val < head1->val) {

			current->next = head1;
			head1 = current;
		}
		else {

			ListNode * p = head1;
			while (p != NULL) {
				if (p->next == NULL ||
					current->val < p->next->val)
				{

					current->next = p->next;
					p->next = current;
					break;
				}
				p = p->next;
			}
		}
	}
	return head1;


}
/*---------reorderList---------------------*/
void Solution::reorderList(ListNode *head) {
	ListNode *fast = head, *slow = head;

	//step1: split list to 2 sub lists
	if (head == NULL || head->next == NULL)return;
	else{
		while (fast != NULL && fast->next != NULL){
			fast = fast->next->next;
			slow = slow->next;
		}

		//step2: reverse the second list
		ListNode *head_n = NULL;
		while (slow != NULL){
			ListNode  *current = slow;
			slow = slow->next;
			current->next = head_n;
			head_n = current;
		}

		//step3: connect first list with reversed list
		ListNode  *l1 = head;
		ListNode  *l2 = head_n;
		while (l2->next != NULL){ //maybe l2->next != NULL
			ListNode  *l1next = l1->next;
			ListNode  *l2next = l2->next;
			l1->next = l2;
			l2->next = l1next;
			l1 = l1next;
			l2 = l2next;
		}
	}
	Solution::printList(head);

}

/*Reverse a linked list from position m to n. Do it in-place and in one-pass.
For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,
return 1->4->3->2->5->NULL.
Run Time: 8ms */

ListNode *Solution::reverseBetween(ListNode *head, int m, int n) {
	int i = 1;
	ListNode *head_n = NULL, *temp = NULL, *head_ = NULL;
	/*step1: find sub list m to n: head_n
			 before m : head_
			 after n : temp
	*/		 
	if (head == NULL || head->next == NULL) return head;
	else if (m == n) return head;
	else{
		ListNode *node = head; 
		while (i <= n){
			//ListNode *t = node;
			

			if (i == 1){
				head_n = node;
			}
			
			if (i == n){
				temp = node->next;
				node->next = NULL;
				break;
			}
			if (i < m){
				head_n = node->next;
				ListNode *node_ = node;
				head_ = node_;
				node = node->next;
			}
			else if (i >= m &&i < n) node = node->next;
			//node = node->next;
			i++;
		}
	

	//step2: reverse list 
		ListNode *reverse = NULL;
		while (head_n != NULL){
			ListNode  *current = head_n;
			head_n = head_n->next;
			current->next = reverse;
			reverse = current;
		}

		//step3: connect
		if (m == 1) 
			head = reverse;
		else{
			//while (head->next != NULL){
			//	head = head->next;
			//}
			head_->next = reverse;
		}
			
		while (reverse->next != NULL){
			reverse = reverse->next;
		}
		reverse->next = temp;
		return head;
	}
	
}

/*Given a sorted linked list, delete all duplicates such that each element appear only once.
For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.*/

ListNode *Solution::deleteDuplicates(ListNode *head) {
	if (head == NULL || head->next == NULL)
		return head;

	else{
		ListNode *node = head;
		while (node->next != NULL){
			ListNode *p = node->next;			
			if (node->val == p->val){
				node->next = p->next; 
			}
			else 
				node = node->next;
		}
		return head;

	}
}

/*Given a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list.
For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.*/

ListNode *Solution::deleteDuplicates_(ListNode *head){
	if (head == NULL || head->next == NULL)
		return head;
	else if (head->val == head->next->val && head->next->next == NULL) return NULL;
	else{
		ListNode *node = head;		
		while (node->next != NULL){
			ListNode *p = node->next;
			if (p->next == NULL) break;
			if (node->val != p->val && p->val != p->next->val){
				node = node->next;
			}
			else{
				while (p->val == p->next->val){					
					p = p->next;
					if (p->next == NULL) break;
				}
				if (head->val == p->val)
					head = p->next;								
				node->next= p->next;
			}

		}
		return head;		
	}
}
/*Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?
For example, Given sorted array A = [1,1,1,2,2,3],
Your function should return length = 5, and A is now [1,1,2,2,3].
思路：
遍历的时候记录重复的元素次数，如果重复则跳过。
记录重复元素的方法可以用包含数值的Hash表或者两个BitMap。
由于要保持输出数组的有序性，当非重复数值的时候我们尽量将数值前移。*/
int Solution::removeDuplicates(int A[], int n) {
	bitmap* exist = new bitmap(32767);
	bitmap* duplicate = new bitmap(32767);

	int count = 0;
	int skip = 0;
	for (int i = 0; i < n; i++)
	{
		if (duplicate->val(A[i]))
		{
			skip++;
			count++;
		}
		else if (exist->val(A[i]))
		{
			duplicate->set(A[i]);
			if (skip > 0)
			{
				A[i - skip] = A[i];
			}
		}
		else
		{
			exist->set(A[i]);
			if (skip > 0)
			{
				A[i - skip] = A[i];
			}
		}

	}
	return n - count;
}

/*Given a sorted array, remove the duplicates in place such that each element appear 
only once and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
For example,Given input array A = [1,1,2]
Your function should return length = 2, and A is now [1,2].*/

int Solution::removeDuplicates_(int A[], int n) {
	bitmap* exist = new bitmap(32767);
	int count = 0;
	int skip = 0;
	for (int i = 0; i < n; i++)
	{
		if (exist->val(A[i]))
		{
			count++;
			skip++;
		}
		else
		{
			exist->set(A[i]);
			A[i - skip] = A[i];
		}

	}
	return n - count;
}

//----------get result-------------------
void Solution::printList(ListNode *head){
	while (head != NULL)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}


//------------Binary Tree--------------------------
TreeNode *Solution::createTree(TreeNode* &head, TreeNode *pp, int *a, int start, int end){
	if (start <= end){
		int mid = (start + end) >> 1;
		head = new TreeNode(a[mid]);
		createTree(head->left, head, a, start, mid-1);
		createTree(head->right, head, a, mid + 1, end);
	}
	return head;
}
		
/*Given a binary tree, return the level order traversal of its nodes' values. 
(ie, from left to right, level by level).44 ms*/
vector<vector<int> >  Solution::levelOrder(TreeNode *root) {
	vector<vector<int> > v;
	if (root == NULL)
		return v;
	vector<TreeNode*>vec;

	vec.push_back(root);
	int cur = 0;
	int last = 1;
	while (cur < vec.size()){
		last = vec.size();
		int start = cur;
		int end = last;
		vector<int> sub_v;
		while (start < end){			
			sub_v.push_back(vec[start]->val);			
			start++;
		}
		v.push_back(sub_v);
		

		while (cur < last){
			if (vec[cur]->left != NULL)
				vec.push_back(vec[cur]->left);
			if (vec[cur]->right != NULL)
				vec.push_back(vec[cur]->right);
			cur++;
		}
	}

	return v;
}

/*Binary Tree Level Order Traversal II Total 
Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
(ie, from left to right, level by level from leaf to root). 56 ms */
vector<vector<int> > Solution::levelOrderBottom(TreeNode *root) {
	vector<vector<int> > v;
	if (root == NULL)
		return v;
	vector<TreeNode*>vec;

	vec.push_back(root);
	int cur = 0;
	int last = 1;
	while (cur < vec.size()){
		last = vec.size();
		//save in sub_v
		int start = cur;
		int end = last;
		vector<int> sub_v;
		while (start < end){
			sub_v.push_back(vec[start]->val);
			start++;
		}
		//save in v
		v.push_back(sub_v);


		while (cur < last){
			if (vec[cur]->left != NULL)
				vec.push_back(vec[cur]->left);
			if (vec[cur]->right != NULL)
				vec.push_back(vec[cur]->right);
			cur++;
		}
	}
	//reverse vector v to res
	vector<vector<int>> res;
	for (int i = 0; i<v.size(); i++)
		res.push_back(v[(int)v.size() - i - 1]);
	return res;
}

/*Binary Tree Preorder Traversal 
Recursive solution is trivial, do it iteratively. 8 ms*/
vector<int> Solution::preorderTraversal(TreeNode *root) {
	//---------iterative--------------
	vector<int> v;
	if (root == NULL)
		return v;
	vector<TreeNode*> vec;
	vec.push_back(root);
	while ( vec.size() > 0){
		TreeNode *nd = vec.back();
		vec.pop_back();
		v.push_back(nd->val);
		if (nd->right != NULL)
			vec.push_back(nd->right);
		if (nd->left != NULL)
			vec.push_back(nd->left);
	}
	return v;


	//-------recursive-----------------------
	/*cout << root->val << " ";
	vector<int> v;
	v.push_back(root->val);
	if (root->left == NULL && root->right != NULL){
		v.push_back(root->right->val);
		cout << root->right->val << " ";
		return v;
	}
	if (root->left != NULL && root->right == NULL){
		v.push_back(root->left->val);
		cout << root->left->val << " ";
		return v;
	}
	preorderTraversal(root->left);
	preorderTraversal(root->right);*/
}


/*Postorder Traversal:
1. Push root to first stack.
2. Loop while first stack is not empty
	2.1 Pop a node from first stack and push it to second stack
	2.2 Push left and right children of the popped node to first stack
3. Print contents of second stack  8 ms*/
vector<int> Solution::postorderTraversal(TreeNode *root) {
	vector<int> v;
	if (root == NULL)
		return v;
	vector<TreeNode*> vec1,vec2;
	vec1.push_back(root);
	while (vec1.size() > 0){
		TreeNode *nd = vec1.back();
		vec2.push_back(nd);
		vec1.pop_back();
		if (nd->left != NULL)
			vec1.push_back(nd->left);
		if (nd->right != NULL)
			vec1.push_back(nd->right);
	}
	while (vec2.size() > 0){
		v.push_back(vec2.back()->val);
		vec2.pop_back();
	}
	return v;
	
}

/*设计一个函数可以返回树的每条路径的波幅。所谓波幅就是路径上所有节点的值的最大差值。
要求复杂度为O（N）。我用了recursion，遍历左右两边子树，把每次的结果存在static vector里，最后找出答案。*/
void Solution::calPath(TreeNode* root){
	vector<TreeNode*>vec1, vec2;
	if (root == NULL)
		return;	
	TreeNode *nd = root;
	vec1.push_back(nd);
	while (vec1.size()>0){
		nd = vec1.back();
		vec2.push_back(nd);
		vec1.pop_back();
		if (nd->right != NULL)
			vec1.push_back(nd->right);
		if (nd->left != NULL)
			vec1.push_back(nd->left);
		if (nd->right == NULL && nd->left == NULL){
			printVec(vec2);		
			TreeNode *tmp = vec2.back();
			vec2.pop_back();
			if (vec2.back()->right == tmp)//如果pop出的元素是栈顶元素的右儿子，则pop该元素
				vec2.pop_back();
			if (vec2.back()->right == NULL &&vec2.back()->left == tmp)//如果pop出的元素是栈顶元素的左儿子且右儿子为空，则pop该元素
				vec2.pop_back();
		}
	}
}

void Solution::printVec(vector<TreeNode*> vec){
	while (vec.size() > 0){
		cout << vec.back()->val<<" ";
		vec.pop_back();
	}
	cout << endl;
}


/*shuffle问题。A B C D四个整数，怎样排列可以使得abs(s1-s2)+abs(s2-s3)+abs(s3-s4)的值最小。
s1-s4是重新排列后的整数。要求O（1）复杂度。我用了vector存了abcd，然后sort（），
每次取vector最大和最小值，按序存到新vector里面。*/

/*Binary Tree Maximum Path Sum
Given a binary tree, find the maximum path sum.
The path may start and end at any node in the tree.
Thoughts:1) Recursively solve this problem
基本的思路就是，在递归中计算包含该root的最大值并更新至max[0]
包含该root的最大值有如下几种可能：1.root本身；2.root和左子树中一条路径；
3.root和右子树中一条路径；4.左子树一条路径和root和右子树一条路径。其中取最大就可更新至max[0]
其中1，2，3可用来计算上一级的root的最大值，所以要传回去。
最终，对于最上层的root来说，数内的最大路径不一定要经过根，但由于每个节点都遍历到，其最大值已经存在max[0]里面了。140 ms*/
int Solution::maxPathSum(TreeNode *root) {
	int sum = INT_MIN+10000;
	findMaxSum(root, sum);
	return sum;
}
/*每次更新一个节点，分为local maximum (max_sum) and global maximum(max_global),
local不需要考虑parent节点，所以需要把三数之和进行比较，global需要连接parent节点，因此不能把三个数加和*/
int Solution::findMaxSum(TreeNode* root, int& max_sum){ 
	if (root == NULL) return INT_MIN+10000;
	if (root->right == NULL && root->left == NULL){
		max_sum = max(max_sum,root->val);
		return root->val;		
	}		
	int a = findMaxSum(root->left, max_sum);
	int b = findMaxSum(root->right, max_sum);	
	int max_global = max3(root->val+a, root->val+b,root->val);	
	max_sum = max3(max_global, max_sum,root->val+a+b);
	return max_global;	
}

int Solution::max(int a, int b){
	return (((a) >(b)) ? (a) : (b));
}

int Solution::max3(int a, int b,int c){
	return (a > b ? (a > c ? a : c) : (b > c ? b : c));
}

//-----level order create tree-----------
TreeNode* Solution::CreateBitree(TreeNode *pNode, int *a){
		int END_OF_TREE = '#';
		int END_OF_MAX = -858993460;
		int i = 0;
		pNode = new TreeNode(a[i]);
		queue <TreeNode*> q;
		q.push(pNode);
		while (q.size() > 0 && i <= iter){
			TreeNode* nd = q.front();
			q.pop();
			if (a[i + 1] == END_OF_TREE || a[i + 1] == END_OF_MAX)
				nd->left = NULL;
			else{
				nd->left = new TreeNode(a[i + 1]);
				q.push(nd->left);
			}

			if (a[i + 2] == END_OF_TREE || a[i + 2] == END_OF_MAX)//need to change 
				nd->right = NULL;
			else{
				nd->right = new TreeNode(a[i + 2]);
				q.push(nd->right);
			}

			i = i + 2;
		}
		return pNode;
	}



/*int Solution::findMaxSum(TreeNode* root, int& max_sum){
	if (root == NULL){
		return INT_MIN;
	}
	if (root->left == NULL && root->right == NULL){
		max_sum = max_sum < root->val ? root->val : max_sum;
		return root->val;
	}

	int leftMax = findMaxSum(root->left, max_sum);
	int rightMax = findMaxSum(root->right, max_sum);
	int childMax = max(leftMax, rightMax);
	int whole = root->val;
	if (root->left) whole += leftMax;
	if (root->right) whole += rightMax;
	max_sum = max(max(root->val, childMax + root->val), max(whole, max_sum));
	//return value:
	int ret = max(root->val, root->val + childMax);
	return ret;
}
int Solution::maxPathSum(TreeNode *root) {
	int max_sum = INT_MIN;
	findMaxSum(root, max_sum);
	return max_sum;
}*/
