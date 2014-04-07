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
			a[j] = a[j - 1] ;
			j--;
		}
		a[j] = x;
		
	}
	return a[n-1];
		
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
	// head is the first element of resulting sorted list
	ListNode  * head1 = NULL;
	while (head != NULL) {
		ListNode  * current = head;
		head = head->next;
		if (head1 == NULL || current->val < head1->val) {
			// insert into the head of the sorted list
			// or as the first element into an empty sorted list
			current->next = head1;
			head1 = current;
		}
		else {
			// insert current element into proper position in non-empty sorted list
			ListNode * p = head1;
			while (p != NULL) {
				if (p->next == NULL || // last element of the sorted list
					current->val < p->next->val) // middle of the list
				{
					// insert into middle of the sorted list or as the last element
					current->next = p->next;
					p->next = current;
					break; // done
				}
				p = p->next;
			}
		}
	}
	return head1;

	
}
/*---------reorderList----------------------
本题思路如下：首先将题目所给单链表从中间分割为两个单链表，
再将后半个单链表反向，最后合并两个单链表即可。*/
void Solution::reorderList(ListNode *head) {
	ListNode *fast = head, *slow = head;

	//step1: split list to 2 sub list
	if (head != NULL || head->next !=NULL){
		while (fast != NULL && slow != NULL){
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
		while (head_n != NULL){


		}
		
	}

}
