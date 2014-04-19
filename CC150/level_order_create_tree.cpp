
#include<iostream>
#include<queue>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* CreateBitree(TreeNode *pNode, int *a)//level order create tree
{
	int END_OF_TREE = '#';	
	int i = 0;
	pNode = new TreeNode(a[i]);
	queue <TreeNode*> q;
	q.push(pNode);
	while (q.size() > 0 && i < 6){
		TreeNode* nd = q.front();
		q.pop();
		if (a[i + 1] != END_OF_TREE)
			nd->left = new TreeNode(a[i + 1]);
		if (a[i + 2] != END_OF_TREE)
			nd->right= new TreeNode(a[i + 2]);
		q.push(nd->left);
		q.push(nd->right);
		i = i + 2;
	}
	return pNode;
}

	void main(){
		int tree[] = {0,1,2,3,4,5,'#' };
		
		TreeNode *pRoot = NULL;
		pRoot = CreateBitree(pRoot, tree);
		system("pause");
	}
