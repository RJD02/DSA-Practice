#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int data;
	vector<TreeNode*> children;
	TreeNode() {
		data = 0;
		children = vector<TreeNode*>();
	}
	TreeNode(int data) {
		this->data = data;
	}
};