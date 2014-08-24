#include <iostream>
using namespace std;

typedef struct linkList{
	int data;
	linkList *next;
}linkList;

linkList* init(int a[], int n){
	linkList *head = NULL, *p = NULL;
	for (int i = 0; i < n; ++i){
		linkList *nd = new linkList();
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

int findNthToLast(linkList *head, int n){
	if (head == NULL || n < 1) return NULL;
	linkList *p = head, *q = head;
	while ( n > 0 && q ){
		q = q->next;
		--n;
	}
	if (n > 0) return NULL;
	while (q){
		p = p->next;
		q = q->next;
	}
	return p->data;
}


int main(){
	int a[] = { 1, 6, 2, 3, 4, 5};
	linkList *head = init(a, 6);
	cout << findNthToLast(head, 2) << endl;
	system("pause");
	return 0;
}
