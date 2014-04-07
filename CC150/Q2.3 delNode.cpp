#include <iostream>
using namespace std;

typedef struct node{
	int data;
	node *next;
}node;

node* init(int a[], int n){
	node *head = NULL, *p = NULL;
	for (int i = 0; i<n; ++i){
		node *nd = new node();
		nd->data = a[i];
		if (i == 0){
			head = p = nd;
			continue;
		}
		p->next = nd;
		p = nd;
	}
	return head;
}

bool remove(node *c){
	if (c == NULL || c->next == NULL) return false;
	node *q = c->next;
	c->data = q->data;
	c->next = q->next;
	delete q;
	return true;
}
void print(node *head){
	while (head){
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main(){
	int n = 10;
	int a[] = {
		9, 2, 1, 3, 5, 6, 2, 6, 3, 1
	};
	node *head = init(a, n);
	int cc = 3;
	node *c = head;
	for (int i = 1; i<cc; ++i) c = c->next;
	print(head);
	if (remove(c))
		print(head);
	else
		cout << "failure" << endl;
	getchar();
	return 0;
}
