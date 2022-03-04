#pragma once
//Interface file Node.h

#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

class Node {
	public:
		Node();
		Node(int n);
		Node(int n, Node* parent, Node* l, Node* r);
		int key;
		Node* p;
		Node* left;
		Node* right;
		char color;	//b for black, r for red
};


#endif