#include <iostream>
using namespace std;

typedef struct node{
	int data;
	node *next;
}node;


node* init(int a[], int n, int m){
	node *head = NULL, *p = NULL, *q = NULL;
	for (int i = 0; i<n; ++i){
		node *nd = new node();
		nd->data = a[i];
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

void print(node *head){
	while (head){
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
	getchar();
}
node* loopstart(node *head){
	node *fast = head;
	node *slow = head;
	while (fast != NULL&&fast->next != NULL){
		fast = fast->next->next;
		slow = slow->next;

		if (fast == slow)break;
	}

	if (fast == NULL&&fast->next == NULL){
		return NULL;
	}

	slow = head;
	while (slow != fast)
	{
		fast = fast->next;
		slow = slow->next;
	}
	

	return fast;
}


int main(){
	int n = 10, m = 3;// m<n
	int a[] = {
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9
	};
	node *head = init(a, n, m);
	node *p = loopstart(head);
	if (p)
		cout << p->data << endl;
	getchar();
	return 0;
}
