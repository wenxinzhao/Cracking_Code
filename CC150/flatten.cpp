#include <iostream>
#include <vector>
#include <algorithm> 
#include <queue>
#include <cmath>

using namespace std;

struct ListNode {
int val;
ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//----list initialization-------------
ListNode *initList(int n, int a[]){
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

TreeNode *createTree(TreeNode* &head, TreeNode *pp, int *a, int start, int end){
	if (start <= end){
		int mid = (start + end) >> 1;
		head = new TreeNode(a[mid]);
		createTree(head->left, head, a, start, mid-1);
		createTree(head->right, head, a, mid + 1, end);
	}
	return head;
}
 vector<int> preorderTraversal(TreeNode *root) {
    	vector<int> v;
    	if (root == NULL)
    		return v;
    	vector<TreeNode*> vec;
    	vec.push_back(root);
    	while ( vec.size() > 0){
    		TreeNode *nd = vec.back();
    		vec.pop_back();
    		v.push_back(nd->val);
    		if (nd->right != NULL)
    			vec.push_back(nd->right);
    		if (nd->left != NULL)
    			vec.push_back(nd->left);
    	}
    	return v;
    }

void createNewTree(TreeNode* &head,vector<int> v){
	if(v.size() != 0){

	head  = new TreeNode(v.back() );
	v.pop_back();
	createNewTree(head->right, v);
	}
}


void flatten(TreeNode *root) {
		if(root == NULL)
			return;
/*        vector<int> v = preorderTraversal(root);
		std::reverse(v.begin(), v.end());
		root = NULL;
 		createNewTree(root, v);	*/	
		vector<TreeNode*> vec;
		TreeNode* p = NULL;
		//p->left = NULL;
    	vec.push_back(root);
		while(vec.size() > 0){
			TreeNode* nd = vec.back();
    		vec.pop_back();
    		if (nd->right != NULL)
    				vec.push_back(nd->right);
    		if (nd->left != NULL)
    				vec.push_back(nd->left);
			nd->left = NULL;
			if(p != NULL)  
            {  
                p->right = nd;  
            }  
			nd->right = NULL;  
			p = nd;
		
		}
}
    
   
TreeNode* CreateBitree(TreeNode *pNode, int *a ,int n){
	int END_OF_TREE = '#';
	int END_OF_MAX = -858993460;
	int i = 0;
	pNode = new TreeNode(a[i]);
	queue <TreeNode*> q;
	q.push(pNode);
	while (q.size() > 0 && i < n){
		TreeNode* nd = q.front();
		q.pop();
		if (a[i + 1] == END_OF_TREE || a[i + 1] == END_OF_MAX)
			nd->left = NULL;
		else{
			nd->left = new TreeNode(a[i + 1]);
			q.push(nd->left);
		}
		if(i == n) break;
		if (a[i + 2] == END_OF_TREE || a[i + 2] == END_OF_MAX)//need to change 
			nd->right = NULL;
		else{
			nd->right = new TreeNode(a[i + 2]);
			q.push(nd->right);
		}

		i = i + 2;
	}
	return pNode;
}

unsigned long long fac(int n)
{
	if (n<0) return 0;
	if (n == 0 || n == 1)return 1;
	if (n>1)
	{
		return n*fac(n - 1);
	}
}
double calculator1(){

	double e = 2.718;
	double sum = 0;
	double v = 0.67;
	for(int k = 0; k<=3; k++)
		sum += pow(2*v,k)/fac(k);
	sum *= pow(e,(-2*v));
	return sum;
}

double calculator2(){
	return (6.0/9.0)*(1.0/0.2) +(2.0/9.0)*(1.0/0.15) +(1.0/9.0)*(1.0/0.1);
}

TreeNode *createListTree(TreeNode* &head, TreeNode *pp, std::vector<int> a,  int start, int end){
	if (start <= end){
		int mid = (start + end) >> 1;
		head = new TreeNode(a[mid]);
		createListTree(head->left, head, a, start, mid-1);
		createListTree(head->right, head, a, mid + 1, end);
	}
	return head;
}
/*http://leetcode.com/2010/11/convert-sorted-list-to-balanced-binary.html*/
TreeNode *sortedListToBST(ListNode *head) {
	if(head == NULL)
		return NULL;
	std::vector<int> v;
	while(head != NULL){
		v.push_back(head->val);
		head = head->next;
	}
	std::reverse(v.begin(), v.end());
	TreeNode* root = NULL, *pp = NULL;

	createListTree(root, pp, v, 0, v.size()-1);
	return root;


}


int main(){
	int a[] = {1,2 ,3,4,5,6,7 };
	int n = 7;
	//int a[] = {1,2};
	//int n = 2;
	TreeNode* root = NULL, *p = NULL;
	TreeNode* treeHead = CreateBitree(root,a,n-1);
    flatten(treeHead);
	double g = calculator1();
	cout << "ans1: " << g << endl;
	cout << "ans2: " << calculator2() << endl;
	TreeNode *ppp = sortedListToBST(initList(7,a));
	cout<< ppp->val<<endl;
	return 0;
}
