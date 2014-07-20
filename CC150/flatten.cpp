#include<iostream>
#include<vector>
#include<queue>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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
        vector<int> v = preorderTraversal(root);
		std::reverse(v.begin(), v.end());
		root = NULL;

		//root  = new TreeNode(v.back());
		//v.pop_back();
 		createNewTree(root, v);		
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
	sum = sum* pow(e,(-2*v));
	return sum;
}

double calculator2(){
	return (6.0/9.0)*(1.0/0.2) +(2.0/9.0)*(1.0/0.15) +(1.0/9.0)*(1.0/0.1);
}

void main(){
	int a[] = {1,2 ,5,3,4,'#',6};
	int n = 7;
	TreeNode* root = NULL, *p = NULL;
	TreeNode* treeHead = CreateBitree(root,a,n-1);
    flatten(treeHead);
	double g = calculator1();
	cout << "ans1: " << g << endl;
	cout << "ans2: " << calculator2() << endl;
	system("pause");
}
