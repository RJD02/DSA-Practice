#include <bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int countNodesRecursive(TreeNode* root) {
	if (!root)
		return 0;
	int hl = 0, hr = 0;
	TreeNode* l = root, *r = root;
	while (l) {
		hl++;
		l = l->left;
	}
	while (r) {
		hr++;
		r = r->right;
	}
	if (hl == hr)
		return (1 << hl) - 1;
	return 1 + countNodesRecursive(root->left) + countNodesRecursive(root->right);
}

int getTreeHeight(TreeNode* root) {
	int height = 0;
	while (root->left) {
		height++;
		root = root->left;
	}
	return height;
}

bool nodeExists(int index, int height, TreeNode* r) {
	TreeNode* root = r;
	int left = 0, right = (1 << height) - 1;
	int count = 0;
	while (count < height) {
		int mid_node = ceil((left + right) / 2);
		if (index >= mid_node) {
			root = root->right;
			left = mid_node;
		} else {
			root = root->left;
			right = mid_node - 1;
		}
		count++;
	}
	return root != NULL;
}

int countNodes(TreeNode* root) {
	if (!root)
		return 0;
	int height = getTreeHeight(root);
	if (height == 0)
		return 1;
	int upper_count = (1 << height) - 1;
	int left = 0, right = upper_count;
	while (left < right) {
		int index_to_find = ceil((left + right) / 2);
		if (nodeExists(index_to_find, height, root)) {
			left = index_to_find;
		} else {
			right = index_to_find - 1;
		}
	}
	return upper_count + left + 1;
}