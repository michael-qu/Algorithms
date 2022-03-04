//Implementation file RBTree.cpp
//The interface of the class RBTree is in the header file RBTree.h

#include <iostream>
#include "Node.h"
#include "RBTree.h"
using namespace std;


RBTree::RBTree() {
	nil = nullptr;
	root = nil;
}
//Left rotate: let x's right child (y) become x's parent;
//let y's left subtree become x's right subtree
void RBTree::Left_Rotate(Node* x) {
	Node* y = x->right;
	//Turn y's left subtree into x's right subtree
	x->right = y->left;
	if (y->left != this->nil)
		y->left->p = x;
	//Link x's parent to y
	y->p = x->p;
	if (x->p == this->nil)
		this->root = y;
	else if (x == x->p->left)
		x->p->left = y;
	else
		x->p->right = y;
	//Put x on y's left
	y->left = x;
	x->p = y;
}
//Right rotate: let x's left child (y) become x's parent;
//let y's right subtree become x's left subtree
void RBTree::Right_Rotate(Node* x) {
	Node* y = x->left;
	//Turn y's right subtree into x's left subtree
	x->left = y->right;
	if (y->right != this->nil)
		y->right->p = x;
	//Link x's parent to y
	y->p = x->p;
	if (x->p == this->nil)
		this->root = y;
	else if (x == x->p->left)
		x->p->left = y;
	else
		x->p->right = y;
	//Put x on y's right
	y->right = x;
	x->p = y;
}
void RBTree::RB_Insert_Fixup(Node* z) {



}
void RBTree::RB_Insert(Node* z) {
	Node* y = this->nil;
	Node* x = this->root;
	while (x != this->nil) {
		y = x;		//Trailing pointer to keep track of x's parent
		if (z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	//After the iteration, x becomes nil, this is where to insert z
	z->p = y;
	if (y == this.nil)
		this->root = z;
	else if (z->key < y->key)
		y->left = z;
	else
		y->right = z;
	z->left = this->nil;
	z->right = this->nil;
	z->color = 'r';
	RB_Insert_Fixup(z);
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
	cout << "Postorder tree walk starts:\n";
	if (x != this->nil) {
		Postorder_Tree_Walk(x->left);
		Postorder_Tree_Walk(x->right);
		cout << x->key << ' ';
		cout << endl;
	}
	cout << "Postorder tree walk ends.\n";
}