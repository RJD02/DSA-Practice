#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	Node* left, *right;
};

struct Node* newNode(int val) {
	Node* n = new Node;
	n -> key = val;
	n->left = n->right = NULL;
	return n;
};

struct Node* insertValue(Node* root, int value, queue<Node*> &q) {
	Node* node = newNode(value);
	if(root == NULL)
		root = node;
	else if(q.front()->left == NULL)
		q.front()->left = node;
	else {
		q.front()->right = node;
		q.pop();
	}

	q.push(node);
	return root;
}

Node* createTree(vector<int> arr) {
	Node* root = NULL;
	queue<Node*> q;
	for(int i = 0; i < arr.size(); i++)
		root = insertValue(root, arr[i], q);
	return root;
}

void solve(Node* root, int &count) {
	// cout << root->key << " ";
	if(root->left)
		solve(root->left, count);
	if(root->right)
		solve(root->right, count);
	if(root->right == NULL and root->left == NULL) {
		// cout << root->key << endl;
		count++;
	}
	cout << endl;
}

int main() {
	string s;
	getline(cin, s);
	stringstream ss(s);
	string num;
	vector<int> v;
	while(getline(ss, num, ' ')) {
		v.push_back(stoi(num));
	}
	Node* root = createTree(v);
	int count = 0;
	solve(root, count);
	cout << count;
	return 0;
}