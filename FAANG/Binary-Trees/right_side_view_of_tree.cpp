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


vector<int> rightSideView(TreeNode* root) {
	queue<TreeNode*> q;
	q.push(root);
	int count = 1;
	vector<int> res;

	while (!q.empty()) {
		TreeNode* node = q.front();
		q.pop(); count--;
		if (node->left)
			q.push(node->left);
		if (node->right)
			q.push(node->right);
		if (count == 0) {
			res.push_back(node->val);
			count = q.size();
		}
	}
	return res;
}

void dfs(TreeNode* root, int level, map<int, int> &mp) {
	if (root->right)
		dfs(root->right, level + 1, mp);
	if (mp[level] == 0)
		mp[level] = root->val;
	if (root->left)
		dfs(root->left, level + 1, mp);
}

vector<int> rightSideViewDFS(TreeNode* root) {
	map<int, int> mp;
	dfs(root, 0, mp);
	vector<int> res;
	for (auto m : mp)
		res.push_back(m.second);
	return res;
}