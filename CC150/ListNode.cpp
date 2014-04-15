#include<vector>
#include<stack>
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
	int cnt = last - cur;
	ListNode *head = NULL, *p = NULL, *q = NULL;
	/*while (cur != 0) {
		vect.pop_back();
		cur--;
	}*/
	//while (/*vect.size()>0*/cnt>0){
	for (int i = 0; i < cnt;i++){
		ListNode *nd = new ListNode(vect.back()->key);
		vect.pop_back();
		if (head == NULL){
			head = p = nd;
			continue;
		}
		p->next = nd;
		p = nd;
		//cnt--;
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

/*Q4.6 Tree_Graph LCA(Lowest Common Ancestor) 
可以从根结点开始，判断以当前结点为根的树中左右子树是不是包含我们要找的两个结点。
如果两个结点都出现在它的左子树中，那最低的共同父结点也出现在它的左子树中。
如果两个结点都出现在它的右子树中，那最低的共同父结点也出现在它的右子树中。
如果两个结点一个出现在左子树中，一个出现在右子树中，那当前的结点就是最低的共同父结点 */
TreeNode* Solution::common_ancestor(TreeNode* head, TreeNode* node1, TreeNode* node2){
	if (head == NULL) 
		return NULL;
	if (head == node1 && head == node2) 
		return head;

	bool isNode1InLeft = Solution::isIn(head->left, node1);
	bool isNode2InLeft = Solution::isIn(head->left, node2);
	if (isNode1InLeft && isNode2InLeft){ // if in left sub tree
		return Solution::common_ancestor(head->left, node1, node2);
	}
	else if (!isNode1InLeft && !isNode2InLeft){ //if in right sub tree
		return Solution::common_ancestor(head->right, node1, node2);
	}
	else return head;

}

bool Solution::isIn(TreeNode* head, TreeNode* node){
	if (head == NULL)
		return false;
	if (head == node)
		return true;
	return Solution::isIn(head->left, node) || isIn(head->right, node);
}

void Solution::postOrder(TreeNode* head){
	if (head->left == NULL && head->right == NULL){
		cout << head->key << " ";
		return;
	}		
	Solution::postOrder(head->left);	
	Solution::postOrder(head->right);	
	cout << head->key << " ";
}

void Solution::inOrder(TreeNode* head){
	if (head->left == NULL && head->right == NULL){
		cout << head->key << " ";
		return;
	}
	Solution::inOrder(head->left);
	cout << head->key << " ";
	Solution::inOrder(head->right);
	
}

void Solution::preOrder(TreeNode* head){
	cout << head->key << " ";
	if (head->left == NULL && head->right == NULL){
		//cout << head->key << " ";
		return;
	}
	Solution::preOrder(head->left);	
	Solution::preOrder(head->right);
}

TreeNode* Solution::minimal(TreeNode *node){
	if (node == NULL) return NULL;
	while (node->left != NULL){
		node = node->left;
	}
	return node;
}

TreeNode* Solution::successor(TreeNode *node){
	if (node == NULL) return NULL;
	if (node->right != NULL) Solution::minimal(node->right);
	else{
		TreeNode *tmp = node->parent;
		while (tmp->key < node->key){
			tmp = tmp->parent;
		}
		return tmp;
	}

}

/* Q4.9
You are given a binary tree in which each node contains a value.
Design an algorithm to print all paths which sum up to that value.
Note that it can be any path in the tree - it does not have to start at the root.
思路： 从head开始遍历树，每到一个节点往上去累加，加到SUM就打印path*/
void Solution::find_sum(TreeNode* head, int sum){
	if (head == NULL) return;
	int sum_ = head->key;
	TreeNode *node_ = head;
	if (sum == sum_) cout << head->key << endl;
	else {
		ListNode *list = NULL, *p= new ListNode(node_->key);

		while (node_->parent != NULL && sum != sum_){
			sum_ += node_->parent->key;	
			ListNode *nd = new ListNode(node_->parent->key);
			if (list == NULL) //for how to create a list, don't forget!!!
				list = p;				
			p->next = nd;
			p = nd; //end
			node_ = node_->parent;			
		}
		if (sum == sum_)
			//cout << head->key << endl;
			Solution::printList(list);
	}
	find_sum(head->left, sum);
	find_sum(head->right, sum);	
}

/*You have two very large binary trees: 
T1, with millions of nodes, and T2, with hundreds of nodes. 
Create an algorithm to decide if T2 is a subtree of T1*/
bool Solution::identical_subtree(TreeNode *head1, TreeNode *head2){
	if (head1 == NULL || head2 == NULL)
		return false;
	TreeNode *nd = searchIn(head1, head2);
	if (nd == NULL)
		return false;
	else
		return matchTree(nd->left, head2->left) && matchTree(nd->right, head2->right);

}

TreeNode *Solution::searchIn(TreeNode* head, TreeNode* node){
	if (head == NULL)
		return NULL;
	if (head->key == node->key){
		return head;
	}		
	searchIn(head->left, node); 
	searchIn(head->right, node);
}

bool Solution::matchTree(TreeNode* nd, TreeNode* node){
	if (nd != NULL && node != NULL){
		if (nd->key != node->key)
			return false;
		return matchTree(nd->left, node->left) && matchTree(nd->right, node->right);
	}
}
