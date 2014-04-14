/*Given a binary search tree, design an algorithm 
which creates a linked list of all the nodes at each depth. 
For example,if you have a tree with depth D, you’ll have D linked lists
<beauty of coding> 3.10*/

#include"ListNode.h"


Solution sul;
int main(){
	sul.initTree();
	/*int a[] = {
		0, 1, 2, 3, 4, 5, 6, 7, 8
	};*/
	int a[] = { 4, 3, 8, 5, 2, 1, 6 };
	int n = 7;
	sul.create_minimal_tree(sul.head, sul.p, a, 0, n-1);
	sul.getDepth(sul.head);
	cout << "the height of tree is:" << sul.maxHeight() << endl;
	/*for (int level = 0; level < sul.maxHeight(); level++){
		sul.printNodeAtLevel(sul.head, level);
		cout << endl;
	}*/
	sul.printNodeAtLevel(sul.head);
	// Q4.6 LCA
	cout << "common ancester is :"<<sul.common_ancestor(sul.head, sul.head->left->left, sul.head->right )->key << endl;
	/*cout << endl << "postOrder"<<" ";
	sul.postOrder(sul.head);
	cout << endl << "inOrder" << " ";
	sul.inOrder(sul.head);
	cout << endl << "preOrder" << " ";
	sul.preOrder(sul.head);*/

	sul.find_sum(sul.head, 7);
	system("pause");

}

