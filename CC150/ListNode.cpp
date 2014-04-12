#include<vector>
#include"ListNode.h"

int cnt;
int d = 0, depth[maxn], num = 0;

void Solution::initTree(){
	p = head = NULL;
	memset(tree, '\0', sizeof(tree));
	cnt = 0;
}

ListNode *Solution::initList(int n, int a[]){
	ListNode *head = NULL, *p = NULL, *q = NULL;
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

ListNode *Solution::initList(vector<TreeNode*>vect, int cur, int last){
	int cnt = last-cur;
	ListNode *head = NULL, *p = NULL, *q = NULL;

	for(int i=0;i<cnt;i++){
		ListNode *nd = new ListNode(vect.back()->key);
		vect.pop_back();
		if (head == NULL){
			head = p = nd;
			continue;
		}
		p->next = nd;
		p = nd;
	}
	return Solution::reverse(head);
}

ListNode* Solution::reverse(ListNode *head){
	ListNode *head_n = NULL;
	while (head != NULL){
		ListNode  *current = head;
		head = head->next;
		current->next = head_n;
		head_n = current;
	}
	return head_n;
}

TreeNode *Solution::create_minimal_tree(TreeNode* &head, TreeNode *pp, int *a, int start, int end){
	if (start <= end){
		int mid = (start + end) >> 1;
		tree[cnt].key = a[mid];
		tree[cnt].parent = pp;
		head = &tree[cnt++];
		create_minimal_tree(head->left, head, a, start, mid - 1);
		create_minimal_tree(head->right, head, a, mid + 1, end);
	}
	return head;
	
}

void Solution::getDepth(TreeNode *head){
	if (head == NULL)
		return;
	d++;
	getDepth(head->left);

	if (head->right == NULL&& head->left == NULL)
		depth[num++] = d;
	getDepth(head->right);
	d--;
}

int Solution::maxHeight(){
	int i = 0;
	int max = depth[i];
	while (depth[i] != 0){
		if (depth[i] > max){
			max = depth[i];
		}
		i++;
	}
	return max;
}


int Solution::printNodeAtLevel(TreeNode* &head, int level){
	if (head == NULL)
		return NULL;	
	if (level == 0){
		cout << head->key << " ";
		return 1; 
	}
	return Solution::printNodeAtLevel(head->left, level - 1)+Solution::printNodeAtLevel(head->right, level - 1);
}

void Solution::printNodeAtLevel(TreeNode* head){
	if (head == NULL)
		return;
	vector<TreeNode*>vec;

	vec.push_back(head);
	int cur = 0;
	int last = 1;
	while (cur < vec.size()){
		last = vec.size();
		Solution::printList(Solution::initList(vec, cur, last));
		while (cur < last){
			//cout << vec[cur]->key << " ";
			if (vec[cur]->left != NULL)
				vec.push_back(vec[cur]->left);
			if (vec[cur]->right != NULL)
				vec.push_back(vec[cur]->right);
			cur++;
		}
		//cout << endl;
		
	}
}

void Solution::printList(ListNode *head){
	while (head != NULL)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}
