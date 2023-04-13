#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

using namespace std;
#include <vector>
#include <bits/stdc++.h>
pair<bool, vector<int>*> getPathUtil(BinaryTreeNode<int>* root, int data) {
    if(!root)
          return { false, NULL };
    if(root->data == data) {
        vector<int>* v = new vector<int>();
        v->push_back(root->data);
        return {true, v};
    } else if(root->data > data) {
        auto left = getPathUtil(root->left, data);
        if(left.first) {
            left.second->push_back(root->data);
            return {true, left.second};
        } else return {false, NULL};
    } else {
        auto right = getPathUtil(root->right, data);
        if(right.first) {
            right.second->push_back(root->data);
            return {true, right.second};
        } else return {false, NULL};
    }
}

vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
    // Write your code here
    return getPathUtil(root, data).second;
}

BinaryTreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }

    return root;
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    int k;
    cin >> k;
    vector<int> *output = getPath(root, k);

    if (output != NULL) {
        for (int i = 0; i < output->size(); i++) {
            cout << output->at(i) << " ";
        }
    }

    delete root;
}