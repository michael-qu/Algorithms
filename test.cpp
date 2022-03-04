//Application file
#include <iostream>
#include <vector>
#include "Node.h"
#include "RBTree.h"
using namespace std;
int main() {
	vector <Node> v;
	int n = 10;
	for (int i = 0; i < n; i++) {
		Node x = Node(i);
		v.push_back(x);
	}
	
	Node x = Node(1);
	Node y = Node(2);
	Node z = Node(3);
	y.left = &x;
	y.right = &z;
	x.p = &y;
	y.p = &y;
	cout << "x.p.key = " << x.p->key << endl;
	cout << "y.p.left.key = " << x.p->left->key << endl;
	RBTree T = RBTree();
	T.root = &y;
	cout << "T.root = " << T.root->key << endl;
	cout << "T's max = " << T.Tree_Maximum(T.root)->key << endl;
	cout << "T's min = " << T.Tree_Minimum(T.root)->key << endl;

	cout << "Inorder tree walk starts:\n";
	T.Inorder_Tree_Walk(T.root);
	cout << endl;
	cout << "Inorder tree walk ends.\n";

	cout << "Preorder tree walk starts:\n";
	T.Preorder_Tree_Walk(T.root);
	cout << endl;
	cout << "Preorder tree walk ends.\n";

	cout << "Postorder tree walk starts:\n";
	T.Postorder_Tree_Walk(T.root);
	cout << endl;
	cout << "Postorder tree walk ends.\n";
}
