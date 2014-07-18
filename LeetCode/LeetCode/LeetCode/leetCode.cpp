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
˼·��
������ʱ����¼�ظ���Ԫ�ش����������ظ���������
��¼�ظ�Ԫ�صķ��������ð�����ֵ��Hash����������BitMap��
����Ҫ�������������������ԣ������ظ���ֵ��ʱ�����Ǿ�������ֵǰ�ơ�*/
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
			if (vec2.back()->right == tmp)//����pop����Ԫ����ջ��Ԫ�ص��Ҷ��ӣ���pop��Ԫ��
				vec2.pop_back();
			if (vec2.back()->right == NULL &&vec2.back()->left == tmp)//����pop����Ԫ����ջ��Ԫ�ص����������Ҷ���Ϊ�գ���pop��Ԫ��
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
������˼·���ǣ��ڵݹ��м���������root������ֵ��������max[0]
������root������ֵ�����¼��ֿ��ܣ�1.root������2.root����������һ��·����
3.root����������һ��·����4.������һ��·����root��������һ��·��������ȡ�����Ϳɸ�����max[0]
����1��2��3������������һ����root������ֵ������Ҫ����ȥ��
���գ��������ϲ���root��˵�����ڵ�����·����һ��Ҫ��������������ÿ���ڵ㶼��������������ֵ�Ѿ�����max[0]�����ˡ�140 ms*/
int Solution::maxPathSum(TreeNode *root) {
	int sum = INT_MIN+10000;
	findMaxSum(root, sum);
	return sum;
}
/*ÿ�θ���һ���ڵ㣬��Ϊlocal maximum (max_sum) and global maximum(max_global),
local����Ҫ����parent�ڵ㣬������Ҫ������֮�ͽ��бȽϣ�global��Ҫ����parent�ڵ㣬���˲��ܰ��������Ӻ�*/
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

/*G&T 1. LC������һ���������־�������Ŀ
2. ����prime ����Ϊ����ǰ׺��prime������ ����239 (2 , 23, 239 are all prime numbers) ,given N ��ӡ���г���ΪN�ĳ���prime 
3. iterator ʵ��next hasnext��flatten list�������� [[7 8 9]  []  [2 3 5] [1 19]] --->   7 2 1 8 3 19 9 5
@A  shuffle���⡣A B C D�ĸ��������������п���ʹ��abs(s1-s2)+abs(s2-s3)+abs(s3-s4)��ֵ��С��
s1-s4���������к���������Ҫ��O��1�����Ӷȡ�������vector����abcd��Ȼ��sort������
ÿ��ȡvector��������Сֵ�������浽��vector���档*/

/*����һ���������Է������ģ�ÿ��·�����Ĳ�������ν��������·�������нڵ���ֵ��������ֵ��
Ҫ�����Ӷ�ΪO��N����������recursion����������������������ÿ�εĽ�������static vector������ҳ��𰸡�*/
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

/*o(n)���㷨ֻ��������ɨ��һ�飬���ܵ��෨��λ���㡣����������˵��
1. ���������ǿɽ������� a ^ b = b ^ a
2. 0 ^ a = a
��ô����������Ԫ�����������㣬������Ϊ�Ǹ�����һ�ε�Ԫ�أ�
������a1 ^ a2 ^ ....�����Խ�������ͬԪ�ؽ���������λ�ã�
����������ͬԪ�أ���������(n - 1)/2��0��������ʣ��һ����һԪ�أ�
���ǵ�������Ϊ������һԪ���Լ����ý⡣*/
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
һ��������������1��ʼ��֮�����ŵ���0���ҳ���������1�ı߽磬Ҳ����˵1�Ľ���������*/

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
���ȣ�ѧϰһ���������֣��ο���������
���������������ϵ����ֱ�ʾ��ʽ���Ȱ�����������2000���꣬��Դ������
�������������·��ţ�
�����ַ�	I	V	X	L	C	D	M
��Ӧ����������	1	5	10	50	100	500	1000
���������� ��ͬ��������д������ʾ����������Щ�������ӵõ����������磺III = 3
С�������ڴ��������ұߣ�����ʾ����������Щ�������ӵõ����������磺VIII = 8С�����֣����ڣ�I��X��C��
С�������ڴ����������ߣ�����ʾ�������ڴ�����ȥС�����õ��������磺IV = 4
����ʹ��ʱ�������������ظ����ó���������һ���������滭���ߣ���ʾ����������1000��������ֻ����3999���ڵ����������ò�������������
���Σ���������ת���������ֹ��򣨽�����3999���ڣ���
��ǰ���������������֣�����ĳ������ǰһ����С�������ϸ�������֮����ȥǰһ����������Ȼ�����ϸ��� */
int Solution::romanToInt(string s) {

	int result = digit(s.at(0));

	for (int i = 0; i < s.length()-1; i++)
	{
		if (digit(s.at(i)) >= digit(s.at(i + 1)))
			result += digit(s.at(i + 1));
		else
			result = result - 2 * digit(s.at(i)) + digit(s.at(i + 1)); // result = result-ǰһ����(С����) + (��һ����(����)-С��) �ϲ�����		
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

vector<vector<string> > vv;
int mcount= 0;
vector<vector<string> > solveNQueens(int n) {
	int *arr = new int[n + 1];	
	NQueens(arr, 1, n);
	cout<< "total queens: "<< mcount << endl;
	return vv;
}

void NQueens(int *arr, int i, int n){
	for(int j= 1; j != n+1; j++){
		arr[i] = j;
		if(verify(arr,i)){
			if(i == n){
				mcount++;
				vv.push_back(getResult(arr,n));
			}
			else 
				NQueens(arr, i+1, n);
		}
	}
}

bool verify( int *arr, int i){
	for(int k= 1; k!=i;k++)
		if(arr[k] == arr[i] || (abs(k-i) == abs(arr[k]-arr[i])) )
			return false;
	return true;
}

vector<string> getResult(int *arr, int n){
	vector<string> v;
	for(int i = 1; i != n; i++){
		string s;
		for(int j = 1; j != n; j++){
			if(arr[i] == j)
				s += 'Q';
			else
				s += '.';

		}
		v.push_back(s);
	}
	return v;
}


bool isBalanced(TreeNode *root) {
	bool ans = true;
    if(root == NULL)
		return true;
	getHeight(root, ans);
	return ans;
}

int getHeight(TreeNode *root, bool isBalanced){
	if(root == NULL) return 0;  
	if(!isBalanced) return -1;  
	int leftHeight = getHeight(root->left, isBalanced);
	int rightHeight = getHeight(root->right, isBalanced);
	if(abs(leftHeight- rightHeight) > 1) isBalanced = false;
	return max(leftHeight, rightHeight) +1;
}

void inorderRecurTraverse( TreeNode *root ){ // inorder recursive
    if( root == NULL ) return;
	inorderRecurTraverse( root->left );
	cout << root->val<< endl;
    inorderRecurTraverse( root->right);
}
