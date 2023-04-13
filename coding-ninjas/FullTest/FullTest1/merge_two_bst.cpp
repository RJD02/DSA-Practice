#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;
template <typename T>
class BinaryTreeNode {
public :
	T data;
	BinaryTreeNode<T> *left;
	BinaryTreeNode<T> *right;

	BinaryTreeNode(T data) {
		this -> data = data;
		left = NULL;
		right = NULL;
	}
	~BinaryTreeNode() {
		if (left)
			delete left;
		if (right)
			delete right;
	}
};



void inOrderTraversal(BinaryTreeNode<int>* root, vector<int> &nodes) {
	if (!root) return;
	inOrderTraversal(root->left, nodes);
	nodes.push_back(root->data);
	inOrderTraversal(root->right, nodes);
}

BinaryTreeNode<int>* buildBalancedBST(vector<int> nodes, int start, int end) {
	if (start > end) return NULL;
	int mid = (start + end) / 2;
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(nodes[mid]);
	root->left = buildBalancedBST(nodes, start, mid - 1);
	root->right = buildBalancedBST(nodes, mid + 1, end);
	return root;
}

BinaryTreeNode<int>* printMergeTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
	// vector<BinaryTreeNode<int>*> nodes1, nodes2, nodes;
	vector<int> nodes1, nodes2, nodes;
	inOrderTraversal(root1, nodes1);
	inOrderTraversal(root2, nodes2);
	int i = 0, j = 0;
	while (i < nodes1.size() and j < nodes2.size()) {
		if (nodes1[i] < nodes2[j]) nodes.push_back(nodes1[i++]);
		else nodes.push_back(nodes2[j++]);
	}
	while (i < nodes1.size()) {
		nodes.push_back(nodes1[i++]);
	}
	while (j < nodes2.size()) {
		nodes.push_back(nodes2[j++]);
	}
	// for (auto i : nodes) cout << i->data << " ";
	return buildBalancedBST(nodes, 0, nodes.size() - 1);
}


BinaryTreeNode<int>* takeInput() {
	int rootData;
	//cout << "Enter root data : ";
	cin >> rootData;
	if (rootData == -1) {
		return NULL;
	}
	BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
	queue<BinaryTreeNode<int>*> q;
	q.push(root);
	while (!q.empty()) {
		BinaryTreeNode<int> *currentNode = q.front();
		q.pop();
		int leftChild, rightChild;
		//cout << "Enter left child of " << currentNode -> data << " : ";
		cin >> leftChild;
		if (leftChild != -1) {
			BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
			currentNode -> left = leftNode;
			q.push(leftNode);
		}
		//cout << "Enter right child of " << currentNode -> data << " : ";
		cin >> rightChild;
		if (rightChild != -1) {
			BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
			currentNode -> right = rightNode;
			q.push(rightNode);
		}
	}
	return root;
}
// A utility function to print inorder traversal of a given binary tree
void printInorder( BinaryTreeNode<int>* node)
{
	if (node == NULL)
		return;

	/* first recur on left child */
	printInorder(node->left);

	cout << node->data << " ";

	/* now recur on right child */
	printInorder(node->right);
}

int main() {
	BinaryTreeNode<int>* root1 = takeInput();
	BinaryTreeNode<int>* root2 = takeInput();
	BinaryTreeNode<int>* node = printMergeTrees(root1, root2);
	printInorder(node);
	delete root1;
	delete root2;

	return 0;
}
