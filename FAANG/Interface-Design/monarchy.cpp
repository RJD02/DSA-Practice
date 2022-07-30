#include<bits/stdc++.h>
using namespace std;

/*
 Questions to ask:
 1. Are these names repeating ie will there exist children whose names are same
 1. Can we implement other helper classes/objects
 */

class Person {
public:
	string name;
	bool isAlive;
	vector<Person*> children;
	Person* parent;
	Person(string name) {
		this->name = name;
		this->isAlive = true;
		this->parent = NULL;
	}
};

class Monarchy {
	map<string, Person*> monarch;
	string first_monarch;
public:
	void birth(string child, string parent) { // T: O(1)
		monarch[child] = new Person(child);
		if (parent == "NONE") {
			first_monarch = child;
			return;
		}
		monarch[child]->parent = monarch[parent];
		monarch[parent]->children.push_back(monarch[child]);
	}

	void death(string name) { // T: O(1)
		monarch[name]->isAlive = false;
	}

	void dfs(Person* node, vector<string>& res) { // T: O(number of children)
		if (node->isAlive)
			res.push_back(node->name);
		vector<Person*> children = node->children;
		for (auto child : children) {
			dfs(child, res);
		}
	}

	vector<string> getOrderOfSuccession() { // T: O(number of children)
		vector<string> res;
		dfs(monarch[first_monarch], res);
		return res;
	}
};

int main() {
	Monarchy k;
	k.birth("Jake", "NONE");
	k.birth("Catherine", "Jake");
	k.birth("Tom", "Jake");
	k.birth("Celine", "Jake");
	k.birth("Peter", "Celine");
	k.birth("Jane", "Catherine");
	k.birth("Mark", "Catherine");
	k.birth("Farah", "Jane");
	k.death("Jake");
	vector<string> res = k.getOrderOfSuccession();
	for (auto i : res)
		cout << i << endl;
	return 0;
}