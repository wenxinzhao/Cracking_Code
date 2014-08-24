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


bool deleteNode(linkList *n){
	if (n == NULL || n->next == NULL) return false;	
	n->data = n->next->data;
	n->next = n->next->next;
	return true;
}



				
			
int main(){
	int a[] = { 1, 6, 2, 3, 4, 5};
	linkList *head = init(a, 6);

	int cc = 3;
	linkList *node = head;
	for (int i = 1; i < cc; ++i) 
		node = node->next;
	cout << deleteNode(node) << endl;

	system("pause");
	return 0;
}
