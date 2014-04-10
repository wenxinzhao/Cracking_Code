#include"leetCode.h"

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

//----------get result-------------------
void Solution::printList(ListNode *head){
	while (head != NULL)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}


//-------------Bit Map---------------------
bitmap::bitmap(int n) {
	len = n / 32 + 1;
	map = new unsigned int[len];
	reversemap = new unsigned int[len];


	for (int i = 0; i < len; i++) {
		map[i] = 0;
		reversemap[i] = 0;
		zero = false;
	}
}

void bitmap::set(int k) {
	bool reverse = true;
	if (k == 0) {
		zero = true;
	}
	else if (k < 0) {
		reverse = false;
		k = -k;
	}
	int a = k / 32;
	int b = k % 32;


	if (a >= len) {
		return;
	}
	else {
		if (reverse) {
			int tmp = reversemap[a] / pow(2, b);
			if (tmp % 2 == 0) {
				reversemap[a] += pow(2, b);
			}
		}
		else {
			int tmp = map[a] / pow(2, b);
			if (tmp % 2 == 0) {
				map[a] += pow(2, b);
			}
		}
	}
}

bool bitmap::val(int k) {
	bool reverse = true;
	if (k == 0) {
		return zero;
	}
	else if (k < 0) {
		reverse = false;
		k = -k;
	}
	int a = k / 32;
	int b = k % 32;


	if (a >= len) {
		return false;
	}
	else {
		if (reverse) {
			int tmp = reversemap[a] / pow(2, b);
			if (tmp % 2 == 1) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			int tmp = map[a] / pow(2, b);
			if (tmp % 2 == 1) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}
//------------------------------------------

