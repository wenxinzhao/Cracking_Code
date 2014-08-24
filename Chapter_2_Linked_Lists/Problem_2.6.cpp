#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode node(NULL);
//---------------------------
class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == NULL)
			return false;
		int count = 10000;
		ListNode*slow = head;
		ListNode*fast = head;

		do
		{
			if (slow == NULL)
				return false;
			else
				slow = slow->next;
			if (fast->next == NULL || fast->next->next == NULL)
				return false;
			else
				fast = fast->next->next;
			if (slow == fast)
			{
				return true;
			}
			else
			{
				count--;
			}
			if (count == 0)
				return false;
		} while (true);
	}
	
};
//--------------------------
ListNode* initList(int a[], int n, int m){
	ListNode *head = NULL, *p = NULL,*q = NULL;
	for (int i = 0; i < 10; i++){
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
//---------------------------
Solution sul;
void main(){
	int a[] = {1,2,3,4,5,1,6,7,8,9,0};
	int n = 10, m = 2;
	if (sul.hasCycle(initList(a, n, m)))
		cout << "the list has a circle" << endl;
	else 
		cout << "the list has no circle" << endl;
	
	system("pause");

}

