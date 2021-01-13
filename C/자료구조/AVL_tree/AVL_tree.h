#ifndef _AVL__TREE_H_
#define	_AVL__TREE_H_

typedef int element;

typedef struct Node {
	element item;
	struct Node* left;
	struct Node* right;
} Node;

Node* reBalance(Node** p);
int getBF(Node* p);
int getHeight(Node* p);
Node* RL_rotate(Node* parent);
Node* LR_rotate(Node* parent);
Node* RR_rotate(Node* parent);
Node* LL_rotate(Node* parent);

#endif // _AVL__TREE_H_