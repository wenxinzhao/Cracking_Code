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



ListNode *addLists(ListNode *s1, ListNode *s2){
	if (s1 == NULL) return s2;
	if (s2 == NULL) return s1;
	ListNode *res = NULL, *p = NULL;
	int c = 0;
	while (s1 != NULL && s2 != NULL)
	{
		int tmp = s1->val + s2->val + c;
		ListNode *nd = new ListNode(tmp % 10);
		c = tmp / 10;
		if (res == NULL)
			res = p = nd;
		else{
			p->next = nd;
			p = nd;
		}	
		if (s1->next == NULL || s2->next == NULL)
			break;
		s1 = s1->next;
		s2 = s2->next;		
	}
	while (s1->next != NULL){
		int tmp = s1->next->val + c;
		ListNode *nd = new ListNode(tmp % 10);
		p->next = nd;
		p = nd;
		if (s1->next != NULL)
			s1 = s1->next;
	}
	while (s2->next != NULL){
		int tmp = s2->next->val + c;
		ListNode *nd = new ListNode(tmp % 10);
		p->next = nd;
		p = nd;
		if (s2->next != NULL)
			s2 = s2->next;
	}
	return res;
}

int main(){
	int sa1[] = { 7, 1, 6 ,5};
	int sa2[] = { 5, 9, 3 };
	ListNode *s1 = initList(sa1, 4);
	ListNode *s2 = initList(sa2, 3);
	addLists(s1, s2);
	system("pause");
	return 0;
}
