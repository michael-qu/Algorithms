//Application file
#include <iostream>
#include "Node.h"
#include "RBTree.h"
using namespace std;

int main() {
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

}
