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
};

using namespace std;
/***********************************************************
    Following is the Binary Tree Node class structure

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
    };

***********************************************************/
#include <bits/stdc++.h>
unordered_map<int, int> mp;
BinaryTreeNode<int> *buildTreeHelper(int *inorder, int *postorder , int inStart, int inEnd, int &preIdx) {
    if(inStart > inEnd) return NULL;
    int curr = postorder[preIdx--];
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(curr);
    if(inStart == inEnd) return root;
    int rootIdx = mp[curr];
    root->right = buildTreeHelper(inorder, postorder, rootIdx + 1, inEnd, preIdx);
    root->left = buildTreeHelper(inorder, postorder, inStart, rootIdx - 1, preIdx);
    return root;
}

BinaryTreeNode<int>* buildTreeRec(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
    unordered_map<int, int> mp;
    for(int i = 0; i < inLength; i++) mp[inorder[i]] = i;
    int preIdx = postLength - 1;
    return buildTreeHelper(inorder, postorder, 0, inLength - 1, preIdx);
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

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}

int main() {
    // int size;
    // cin >> size;
    // int *post = new int[size];
    // int *in = new int[size];
    // for (int i = 0; i < size; i++) cin >> post[i];
    // for (int i = 0; i < size; i++) cin >> in[i];
    int in[] = { 4, 8, 2, 5, 1, 6, 3, 7 };
    int post[] = { 8, 4, 5, 2, 6, 7, 3, 1 };
    int n = sizeof(in) / sizeof(in[0]);
    int size = n;
    BinaryTreeNode<int> *root = buildTreeRec(post, size, in, size);
    printLevelATNewLine(root);
}