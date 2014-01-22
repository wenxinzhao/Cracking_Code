#include <iostream>
using namespace std;

typedef struct node{
	int data;
	node *next;
}node;


node* init(int a[], int n){
	node *head = NULL, *p;
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


node* plusList(node* L1, node* L2){


}

int main(){


	int n = 4;
	int a[] = {
		1, 2, 9, 3
	};
	int m = 3;
	int b[] = {
		9, 9, 2
	};

	node *p = init(a, n);
	node *q = init(b, m);
	plusList(p, q);


}
