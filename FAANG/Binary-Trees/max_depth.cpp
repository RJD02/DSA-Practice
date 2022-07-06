#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

Node* treeBuilder() {
	int d;
	cin >> d;
	if(d == -1)
		return NULL;
	Node* n = new Node(d);
	n->left = treeBuilder();
	n->right = treeBuilder();
	return n;
}

int maxDepth(Node* root) {
	// cout << root->data << endl;
	if(root->left == NULL and root->right == NULL) {
		// Leaf node
		return 1;
	}
	int h1 = 0, h2 = 0;
	if(root->left != NULL)
		 h1 = maxDepth(root->left);
	if(root->right != NULL)
	 	h2 = maxDepth(root->right);

	return 1 + max(h1, h2);
}

void inOrderTraversal(Node* root) {
	if(root == NULL)
		return;
	inOrderTraversal(root->left);
	cout << (root->data) << " ";
	inOrderTraversal(root->right);
}

int main() {
	Node* root = treeBuilder();
	// inOrderTraversal(root);

	cout << maxDepth(root) << endl;
	return 0;
}