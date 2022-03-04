#pragma once
//Interface file RBTree.h

#ifndef RBTREE_H
#define RBTREE_H

#include <iostream>
#include "Node.h"
using namespace std;

class RBTree {
	public:
		Node* root;
		Node* nil;
		RBTree();
		void Left_Rotate(Node* x);
		void Right_Rotate(Node* x);
		void RB_Insert_Fixup(Node* z);
		void RB_Insert(Node* z);
		Node* Tree_Search(Node* x, int k);
		Node* Tree_Minimum(Node* x);
		Node* Tree_Maximum(Node* x);
		Node* Tree_Successor(Node* x);
		Node* Tree_Predecessor(Node* x);
		void Inorder_Tree_Walk(Node* x);
		void Preorder_Tree_Walk(Node* x);
		void Postorder_Tree_Walk(Node* x);
};
#endif