#include <bits/stdc++.h>
using namespace std;

/* Definition for a binary tree node. */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void dfs(TreeNode* root, vector<int>& v) {
	if(root->left)
		dfs(root->left, v);
	v.push_back(root->val);
	if(root->right)
		dfs(root->right, v);
}

bool isValid(TreeNode* root) {
	vector<int> v;
	dfs(root, v);
	for(int i = 0; i < v.size() - 1; i++) {
		if(v[i + 1] <= v[i])
			return false;
	}
	return true;
}

int main() {
	;
}