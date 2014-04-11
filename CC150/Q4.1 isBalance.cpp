#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn = 100;
struct Node
{
	int key;
	Node *left, *right, *parent;
};

Node *p, *head, tree[maxn];
int cnt;
void init(){
	p = head = NULL;
	memset(tree, '\0', sizeof(tree));
	cnt = 0;

}

void insert(Node* &head, int x){
	if (head == NULL){
		tree[cnt].key = x;
		tree[cnt].parent = p;
		head = &tree[cnt++];
		return;
	}
	p = head;
	if (x < head->key)
		insert(head->left, x);
	else
		insert(head->right, x);
}

int d = 0, depth[maxn],num= 0;
void getDepth(Node *head){
	if (head == NULL)
		return;
	d++;
	getDepth(head->left);
	
	if (head->right == NULL&& head->left == NULL)
		depth[num++] = d;
	getDepth(head->right);
	d--;
}

bool isBalance(){
	int i = 0;
	int max = depth[i], min = depth[i];
	while (depth[i] == 0){
		if (depth[i] > max || depth[i] < 100){
			max = depth[i];
			min = depth[i];
		}
	}
	if (max - min <= 1)
		return true;
	else return false;
}

int main(){
	init();
	int a[] = {
		5, 3, 8, 1, 4, 7, 10, 2, 6, 9, 11, 12
	};
	for (int i = 0; i < 12; i++){
		insert(head, a[i]);
	}
	getDepth(head);
	cout << isBalance() << endl;
	system("pause");

}
