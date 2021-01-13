#include "AVL_tree.h"

#define MAX(a, b) ((a)>(b) ? (a):(b))

Node* LL_rotate(Node* parent) {
	Node* child = parent->left;

	parent->left = child->right;
	child->right = parent;

	return child;
}

Node* RR_rotate(Node* parent) {
	Node* child = parent->right;

	parent->right = child->left;
	child->left = parent;

	return child;
}

Node* LR_rotate(Node* parent) {
	Node* child = parent->left;

	parent->left = RR_rotate(child);
	return LL_rotate(parent);
}

Node* RL_rotate(Node* parent) {
	Node* child = parent->right;

	parent->right = LL_rotate(child);
	return RR_rotate(parent);
}

int getHeight(Node* p) {
	int height = 0;

	if (p) height = MAX(getHeight(p->left), getHeight(p->right)) + 1;
	return height;
}

int getBF(Node* p) {
	if (!p) return 0;
	return getHeight(p->left) - getHeight(p->right);
}

Node* reBalance(Node** p) {
	int BF = getBF(*p);

	if (BF > 1)
		if (getBF((*p)->left) > 0) *p = LL_rotate(*p);
		else					   *p = LR_rotate(*p);
	else if(BF < -1)
		if (getBF((*p)->right) < 0) *p = RR_rotate(*p);
		else					   *p = RL_rotate(*p);
	return *p;
}

//김해교 바보 그리고 권민정 바보