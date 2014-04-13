/*Given a binary search tree, design an algorithm 
which creates a linked list of all the nodes at each depth. 
For example,if you have a tree with depth D, you’ll have D linked lists
<beauty of coding> 3.10*/

#include"ListNode.h"


Solution sul;
int main(){
	sul.initTree();
	int a[] = {
		0, 1, 2, 3, 4, 5, 6, 7, 8
	};
	int n = 9;
	ListNode *Node = NULL;
	sul.create_minimal_tree(sul.head, sul.p, a, 0, 8);
	sul.getDepth(sul.head);
	cout << "the height of tree is:" << sul.maxHeight() << endl;	
	sul.printNodeAtLevel(sul.head);

	/*Write an algorithm to find the ‘next’ node (i.e., in-order successor)of 
	a given node in a binary search tree where each node has a link to its parent.*/

	cout<<"successor is :"<<sul.successor(sul.head->right->left)->key<<endl;
	system("pause");

}
