#include <bits/stdc++.h>
using namespace std;

#define bug(...)		__f (#__VA_ARGS__, __VA_ARGS__)
#define debug(i, j) 	cout << "{" << i << "," << j << "} "

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

class Node {
public:
	char letter;
	Node* parent;
	vector<Node*> children;
	bool isEnd;
	Node() {
		this->parent = NULL;
	}
	Node(char letter) {
		Node();
		this->letter = letter;
	}
};

class Trie {
	Node* root = new Node();
public:
	void insert(string word) {
		Node* temp = root;
		for (auto i : word) {
			bool ok = false;
			for (auto child : temp->children) {
				if (child->letter == i) {
					ok = true;
					temp = child;
					break;
				}
			}
			if (!ok) {
		
				Node* nNode = new Node(i);
				nNode->parent = temp;
				temp->children.push_back(nNode);
				temp = nNode;
			}
		}
		temp->isEnd = true;

	}
	bool search(string word) {
		Node* temp = root;
		int i = 0;
		while (i < (int)word.size()) {
			bool ok = false;
			for (auto child : temp->children) {
				
				if (child->letter == word[i]) {
					// bug(child->letter);
					temp = child; ok = true;
					break;
				}
			}
			if (!ok)
				return false;
			i++;
		}
		// bug(temp->letter);
		return temp->isEnd;
	}
	bool startsWith(string prefix) {
		Node* temp = root;
		int i = 0;
		while (i < (int)prefix.size()) {
			bool ok = false;
			for (auto child : temp->children) {
				if (child->letter == prefix[i]) {
					temp = child; ok = true;
					break;
				}
			}
			if (!ok) 
				return false;
			i++;
		}
		return true;
	}
};

int main() {
	Trie t;
	t.insert("apple");
	t.insert("app");
	t.insert("dog");
	cout << t.search("dog") << endl;
	cout << t.search("app") << endl;
	return 0;
}
