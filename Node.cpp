//Implementation file Node.cpp
//The interface of the class Node is in the header file Node.h

#include <iostream>
#include "Node.h"
using namespace std;

Node::Node() {
	key = 0;
	p = nullptr;
	left = nullptr;
	right = nullptr;
	color = 'b';
}
Node::Node(int n) {
	key = n;
	p = nullptr;
	left = nullptr;
	right = nullptr;
	color = 'b';
}
Node::Node(int n, Node* parent, Node* l, Node* r) {
	key = n;
	p = parent;
	left = l;
	right = r;
	color = 'b';
}