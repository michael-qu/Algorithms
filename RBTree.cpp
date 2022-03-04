//Implementation file RBTree.cpp
//The interface of the class Node is in the header file RBTree.h

#include <iostream>
#include "Node.h"
#include "RBTree.h"
using namespace std;


RBTree::RBTree() {
	nil = nullptr;
	root = nil;
}

void RBTree::RB_Insert_Fixup(Node* z) {



}
void RBTree::RB_Insert(Node* z) {



}
void RBTree::Left_Rotate(Node* z) {



}
void RBTree::Right_Rotate(Node* z) {



}
Node* RBTree::Tree_Search(Node* x, int k) {
	while (x != this->nil && k != x->key) {
		if (k < x->key)
			x = x->left;
		else
			x = x->right;
		return x;
	}
}
Node* RBTree::Tree_Minimum(Node* x) {
	while (x->left != this->nil)
		x = x->left;
	return x;
}
Node* RBTree::Tree_Maximum(Node* x) {
	while (x->right != this->nil)
		x = x->right;
	return x;
}
Node* RBTree::Tree_Successor(Node* x) {
	if (x->right != this->nil) {
		return Tree_Minimum(x->right); //leftmost node in x's right subtree
	}
	Node* y = x->p;
	while (y != this->nil && x == y->right) {
		x = y;
		y = y->p;
	}
	return y;	//the lowest ancestor of x whose left child is also an ancestor of x
}
Node* RBTree::Tree_Predecessor(Node* x) {
	if (x->left != this->nil) {
		return Tree_Maximum(x->left); //rightmost node in x's left subtree
	}
	Node* y = x->p;
	while (y != this->nil && x == y->left) {
		x = y;
		y = y->p;
	}
	return y;	//the lowest ancestor of x whose right child is also an ancestor of x
}

void RBTree::Inorder_Tree_Walk(Node* x) {
	cout << "Inorder tree walk starts:\n";
	if (x != this->nil) {
		Inorder_Tree_Walk(x->left);
		cout << x->key << ' ';
		Inorder_Tree_Walk(x->right);
		cout << endl;
	}
	cout << "Inorder tree walk ends.\n";
}
void RBTree::Preorder_Tree_Walk(Node* x) {
	cout << "Preorder tree walk starts:\n";
	if (x != this->nil) {
		cout << x->key << ' ';
		Preorder_Tree_Walk(x->left);
		Preorder_Tree_Walk(x->right);
		cout << endl;
	}
	cout << "Preorder tree walk ends.\n";
}
void RBTree::Postorder_Tree_Walk(Node* x) {
	if (x != this->nil) {
		Inorder_Tree_Walk(x->left);
		cout << x->key << ' ';
		Inorder_Tree_Walk(x->right);
		cout << endl;
	}


}