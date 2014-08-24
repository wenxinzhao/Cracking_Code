#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

ListNode *initList(int a[], int n){
	ListNode *head = NULL, *p = NULL;
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

ListNode *partition(ListNode *head, int x) {
	if (head == NULL)
		return head;
	ListNode *sub1 = NULL, *sub2 = NULL, *p = NULL, *q = NULL;
	while( head != NULL){
		if (head->val < x){
			ListNode *nd = new ListNode(head->val);
			if (sub1 == NULL)
			{
				sub1 = p = nd;
				head = head->next;
				continue;
			}
			p->next = nd;
			p = nd;
		}
			
		else{
			ListNode *nd = new ListNode(head->val);
			if (sub2 == NULL)
			{
				sub2 = q = nd;
				head = head->next;
				continue;
			}
			q->next = nd;
			q = nd;
		}
		head = head->next;
	}


	if (p == NULL)
		return sub2;
		
	else{
		p->next = sub2;
		return sub1;
	}
	
}

int main(){
	int a[] = {1};
	ListNode *head = initList(a,1);
	partition(head, 0);
	system("pause");
	return 0;
}
