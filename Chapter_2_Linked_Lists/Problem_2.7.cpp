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


ListNode *reverse(ListNode *head, int &count){
	ListNode *reverse = NULL;
	while (head != NULL)
	{
		ListNode *nd = new ListNode(head->val);
		if (reverse == NULL)
			reverse = nd;
		else{
			nd->next = reverse;
			reverse = nd;
		}				
		head = head->next;
		count++;
	}
	return reverse;
}

bool isPalindrome(ListNode *s1) {
	if (s1 == NULL) return false;
	int cnt = 0;
	ListNode *s2 = reverse(s1, cnt);
	int i = 0;
	while (s1 != NULL && s2 != NULL){
		if (s1->val != s2->val)
			return false;
		s1 = s1->next;
		s2 = s2->next;
		i++;
		if (i > (cnt / 2))
			break;
	}
	return true;
}



int main(){
	int sa1[] = { 1, 2, 0, 3, 1};
	ListNode *s1 = initList(sa1, 5);
	cout << isPalindrome(s1) << endl;
	system("pause");
	return 0;
}
