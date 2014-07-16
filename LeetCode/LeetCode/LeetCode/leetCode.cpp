#include"leetCode.h"
#include"bitmap.h"
#include <string>
#include <algorithm>

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

/*G&T 1. LC上面的一个关于数字矩阵的题目
2. 超级prime 定义为所有前缀是prime的数， 比如239 (2 , 23, 239 are all prime numbers) ,given N 打印所有长度为N的超级prime 
3. iterator 实现next hasnext，flatten list交替输出 [[7 8 9]  []  [2 3 5] [1 19]] --->   7 2 1 8 3 19 9 5
@A  shuffle问题。A B C D四个整数，怎样排列可以使得abs(s1-s2)+abs(s2-s3)+abs(s3-s4)的值最小。
s1-s4是重新排列后的整数。要求O（1）复杂度。我用了vector存了abcd，然后sort（），
每次取vector最大和最小值，按序存到新vector里面。*/

/*设计一个函数可以返回树的（每条路径）的波幅。所谓波幅就是路径上所有节点的值的最大差值。
要求复杂度为O（N）。我用了recursion，遍历左右两边子树，把每次的结果存在static vector里，最后找出答案。*/
int Solution::pathAmplitude(TreeNode *root){
	int pathLength = 0;
	findAmplitude(root, pathLength);
	cout << endl;
	return abs(pathLength);
}
int Solution::findAmplitude(TreeNode* root, int& path){
	if (root == NULL) return 1; //wrong
	if (root->right == NULL && root->left == NULL){
		//path = 0;
		return root->val;//return error
	}
	
	int a, b;
	a = findAmplitude(root->left, path);
	b = findAmplitude(root->right, path);	
	


	int max_global;//global respect 2 value
	if (abs(calcAbs(root->val, a)) > abs(calcAbs(root->val, b)))
		max_global = a;
	else 
		max_global = b;
	cout << max_global << " ";
	path = max3(abs(max_global), path, abs(calcAbs(root->val,a,b) ));//local respect 3 value
	return max_global;	
}
int Solution::calcAbs(int a, int b, int c){
	int x = min(a, min(b,c));
	int y = max3(a, b, c);
	if (x < 0)
		return x - y;
	else
		return y - x;
}
int Solution::calcAbs(int a, int b){
	int x = min(a, b);
	int y = max(a, b);
	if (x < 0)
		return x - y;//if two negative value?
	else
		return y - x;
}


int Solution::maxProfit1(vector<int> &prices) {
	if (prices.size() == 0 || prices.size() == 1)
		return 0;
	int* profit = new int[prices.size() - 1];
	for (int i = 0; i<prices.size() - 1; i++)
		profit[i] = prices[i + 1] - prices[i];

	int max = profit[0];
	int cur = profit[0];

	for (int i = 1; i<prices.size() - 1; i++){
		if (cur < 0)
			cur = profit[i];
		else
			cur = cur + profit[i];

		if (max < cur)
			max = cur;
	}

	return max<0 ? 0 : max;

}
int Solution::maxProfit2(vector<int> &prices) {
	if (prices.size() == 0 || prices.size() == 1)
		return 0;
	int *profit = new int[prices.size() - 1];
	for (int i = 0; i<prices.size() - 1; i++)
		profit[i] = prices[i + 1] - prices[i];
	int max = 0;
	for (int i = 0; i < prices.size() - 1; i++){
		if (profit[i]>0)
			max += profit[i];
	}
	return max;
}
int Solution::maxProfit3(vector<int> &prices){
	if (prices.size() <= 1)
		return 0;
	vector<int> subprice;

	int lowest = prices[0];
	int max = 0;
	subprice.push_back(0);
	for (int i = 0; i<prices.size(); i++){
		int profit = prices[i] - lowest;
		if (profit> max)
			max = profit;
		subprice.push_back(max);
		if (prices[i]<lowest)
			lowest = prices[i];
	}

	int ret = subprice[prices.size() - 1];
	int max_2 = 0;
	int highest = prices[prices.size() - 1];
	for (int i = prices.size() - 2; i >= 0; --i){
		int profit_2 = highest - prices[i];
		if (profit_2>max_2)
			max_2 = profit_2;
		int final_profit = max_2 + subprice[i];
		if (final_profit>ret)
			ret = final_profit;
		if (highest<prices[i])
			highest = prices[i];

	}

	return ret;

}

/*o(n)的算法只能是线性扫描一遍，可能的相法是位运算。对于异或来说：
1. 异或运算是可交换，即 a ^ b = b ^ a
2. 0 ^ a = a
那么如果对所有元素做异或运算，其结果为那个出现一次的元素，
理解是a1 ^ a2 ^ ....，可以将所有相同元素交换至相邻位置，
首先运算相同元素，则会产生(n - 1)/2个0异或积，剩余一个单一元素，
他们的异或积为这个单一元素自己，得解。*/
int Solution::singleNumber(int A[], int n) {

	int result = A[0];
	
	for (int i = 1; i < n; i++){
		result = result ^ A[i];
	}
	return result;
		
}

int Solution::singleNumber2(int A[], int n) {
	int one = 0;
	int two = 0;
	int three = 0;
	for (int i = 0; i < n; i++){
		two |= one & A[i];
		one = one ^ A[i];		
		three = ~(one&two);
		one = one & three;
		two = two & three;
	}
	return one;
}
/*Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.*/
int Solution::maxDepth(TreeNode *root) {
	if (root == NULL)
		return 0;
	int nLeft = maxDepth(root->left);
	int nRight = maxDepth(root->right);
	return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
}

/* @Google  In an array starting with 1 's (consecutively) and 
following with 0's, find the boundary of 1's. 
一个数组以连续的1开始，之后接着的是0，找出这个数组1的边界，也就是说1的结束索引。*/

/*Given two binary trees, write a function to check if they are equal or not.
Two binary trees are considered equal if they are structurally 
identical and the nodes have the same value.*/

bool Solution::isSameTree(TreeNode *p, TreeNode *q) {
	if ((p == NULL&& q != NULL) || (p != NULL&& q == NULL))
		return false;
	else if (p == NULL && q == NULL)
		return true;
	else if (p->val == q->val)
		isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	else 
		return false;
}

int Solution::reverse(int x) {
	int r, num = 0;
	bool neg = false;
	if (x < 0){
		x = -x;
		neg = true;
	}		
	while (x != 0){		
		r = x % 10;
		num = num * 10 + r;
		x = x / 10;
	}

	if (neg) num = -num;
	return num;
}

int Solution::numTrees(int n) {
	vector<int> num;
	if (n == 0) return 0; 
	num.push_back(1);
	for (int i = 1; i <= n; i++){
		if (i <= 2) num.push_back(i);
		else{
			num.push_back(0);
			for (int j = 0; j<i; j++)
				num[i] += num[j] * num[i -j -1];
		}
	}
	return num.back();
}

vector<int> Solution::inorderTraversal(TreeNode *root) {
	vector<int> v;
	if (root == NULL)
		return v;
	vector<TreeNode*> vec;
	TreeNode* p = root;
	//vec.push_back(root);
	while (vec.size() > 0 || p){
		if (p != NULL){
			vec.push_back(p);
			p = p->left;
		}
			
		else{
			p = vec.back();
			vec.pop_back();
			v.push_back(p->val);
			p = p->right;
		}		
	}
	return v;
}


int Solution::searchInsert(int A[], int n, int target) {
	for (int i = 0; i < n; i++){
		if (target <= A[i])
			return i;
		else if (target > A[i] && target < A[i + 1])
			return i + 1;
		else if (target > A[i] && i == n-1)
			return i + 1;
		else
			continue;
	}
}
TreeLinkNode *Solution::createLinkTree(TreeLinkNode* &head, TreeLinkNode *pp, int *a, int start, int end){
	if (start <= end){
		int mid = (start + end) >> 1;
		head = new TreeLinkNode(a[mid]);
		createLinkTree(head->left, head, a, start, mid - 1);
		createLinkTree(head->right, head, a, mid + 1, end);
	}
	return head;
}

TreeLinkNode *Solution::connect(TreeLinkNode *root) {
	 if (root == NULL)
		return NULL;
	vector<TreeLinkNode*>vec;

	vec.push_back(root);
	int cur = 0;
	int last = 1;
	while (cur < vec.size()){
		last = vec.size();
		int start = cur;
		int end = last;
		vector<TreeLinkNode*> sub_v;
		while (start < end){
			sub_v.push_back(vec[start]);
			start++;
		}
		for (int i = 1; i < sub_v.size(); i++)
				sub_v[i - 1]->next = sub_v[i];

		while (cur < last){
			if (vec[cur]->left != NULL)
				vec.push_back(vec[cur]->left);
			if (vec[cur]->right != NULL)
				vec.push_back(vec[cur]->right);
			cur++;
		}
	}
	return root;
	
}


void print(int i){
	printf("%d ", i);
}
void show_result(vector<int>nums){
	//for_each(nums.begin(), nums.end(), print);
	for_each(nums.begin(), nums.end(), [=](int i){
		printf("%d ", i);
	});
}

/*
首先，学习一下罗马数字，参考罗马数字
罗马数字是最古老的数字表示方式，比阿拉伯数组早2000多年，起源于罗马
罗马数字有如下符号：
基本字符	I	V	X	L	C	D	M
对应阿拉伯数字	1	5	10	50	100	500	1000
计数规则： 相同的数字连写，所表示的数等于这些数字相加得到的数，例如：III = 3
小的数字在大的数字右边，所表示的数等于这些数字相加得到的数，例如：VIII = 8小的数字，限于（I、X和C）
小的数字在大的数字左边，所表示的数等于大数减去小数所得的数，例如：IV = 4
正常使用时，连续的数字重复不得超过三次在一个数的上面画横线，表示这个数扩大1000倍（本题只考虑3999以内的数，所以用不到这条规则）
其次，罗马数字转阿拉伯数字规则（仅限于3999以内）：
从前向后遍历罗马数字，如果某个数比前一个数小，则加上该数。反之，减去前一个数的两倍然后加上该数 */
int Solution::romanToInt(string s) {

	int result = digit(s.at(0));

	for (int i = 0; i < s.length()-1; i++)
	{
		if (digit(s.at(i)) >= digit(s.at(i + 1)))
			result += digit(s.at(i + 1));
		else
			result = result - 2 * digit(s.at(i)) + digit(s.at(i + 1)); // result = result-前一个数(小的数) + (后一个数(大的)-小的) 合并处理		
	}

	return result;
}

int Solution::digit(char s){
	
	switch (s) {
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
	}
}

string Solution::intToRoman(int num) {
	string a;
	int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	string numerals[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	for (int i = 0; i < 13; i++) {
		while (num >= values[i]) {
			num -= values[i];
			a.append(numerals[i]);
		}
	}
	return a;
}

//============== DP ====================
//int Solution::maxSubArray(int A[], int n) {
//	int sum = 0;
//	int max = INT_MIN;
//	for (int i = 0; i < n; i++){
//		sum += A[i];
//
//		if (sum > max)
//			max = sum;
//		if (sum < 0)
//			sum = 0;
//	}
//	return max;
//}

//======= divide and conquer ==============
int Solution::maxSubArray(int A[], int n) {

	int maxV = INT_MIN;
	return maxArray(A, 0, n - 1, maxV);
}

int Solution::maxArray(int A[], int start, int end, int maxV){
	if (start > end)
		return INT_MIN; // error
	int mid = int((start + end) / 2);
	maxV =  max3(maxArray(A, start, mid - 1, maxV), maxArray(A, mid + 1, end, maxV), maxV);
	// part of left + part of right
	int sum = 0, i = 0, maxV1 = INT_MIN, maxV2 = INT_MIN;
	for (i = mid; i > 0; i--){
		sum += A[i];
		if (sum > maxV2)
			maxV1 = sum;
	}
	sum = 0;
	for (i = mid; i < end; i++){
		sum += A[i];
		if (sum > maxV2)
			maxV2 = sum;
	}
	maxV = max(maxV, maxV1 + maxV2 + A[mid]);
	return maxV;
}

int climbStairs(int n) {
	int result = 0;
	int a1 = 1, a2 = 2;
	if( n < 2)
		return n;
	for(int i = 2; i<=n; i++){
		result = a1+a2;
		a1 = a2;
		a2 = result;
	}
	return result;
}

int permutate(int n, int m){
	int a;
	if (n > m){
		n = n + 1;
		a = fac(n) / fac(n - m);
	}
		
	else{
		m = m + 1;
		a = fac(m) / fac(m - n);
	}
		
	return a;
}

int combinate(int n, int m){
	int a;
	if (n > m){
		n = n + 1;
		a = fac(n) / (fac(n - m) * fac(m));
	}
		
	else{
		m = m + 1;
		a = fac(m) / (fac(m - n) * fac(n));
	}
		
	return a;
}

unsigned long long fac(int n)
{
	if (n<0) return 0;
	if (n == 0 || n == 1)return 1;
	if (n>1)
	{
		return n*fac(n - 1);
	}
}

int removeElement(int A[], int n, int elem) {
	int length;
	sort(A, A + n);
	length  = (sizeof(A)/sizeof(*A));
	return length;
}

