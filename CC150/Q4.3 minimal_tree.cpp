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

void create_minimal_tree(Node* &head,Node *pp, int *a,  int start, int end){
	if (start <= end){
		int mid = (start + end) >> 1;
		tree[cnt].key = a[mid];
		tree[cnt].parent = pp;
		head = &tree[cnt++];
		create_minimal_tree(head->left, head, a, start, mid-1);
		create_minimal_tree(head->right, head, a, mid + 1, end);
	}
}

int d = 0, depth[maxn], num = 0;
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
int maxHeight(){
	int i = 0;
	int max = depth[i];
	while (depth[i] != 0){
		if (depth[i] > max ){
			max = depth[i];
		}
		i++;
	}
	return max;

}


int main(){
	init();
	int a[] = {
		0, 1, 2, 3, 4, 5, 6, 7, 8
	};
	int n = 9;
	create_minimal_tree(head, p,  a, 0, 8);
	
	getDepth(head);
	cout << maxHeight()<<endl;
	system("pause");

}
