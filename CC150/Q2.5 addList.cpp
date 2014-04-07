#include <iostream>
using namespace std;

typedef struct node{
	int data;
	node *next;
}node;


node* init(int a[], int n){
	node *head = NULL, *p= NULL;
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

void print(node *head){
	while (head){
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
	getchar();
}

node *result = new node();
int value = 0;
node* plusList(node* L1, node* L2){
	
	
	if (L1 != NULL)
		value += L1->data;

	if (L2 != NULL)
		value += L2->data;

	result->data = value % 10;

	result = result->next;
	
	plusList(L1->next, L2->next);
	

	return result;

}

int main(){


	int n = 3;
	int a[] = {7,1,6};
	int m = 3;
	int b[] = {5,9,2};

	node *p = init(a, n);
	node *q = init(b, m);
	plusList(p, q);

	print(result);

}
