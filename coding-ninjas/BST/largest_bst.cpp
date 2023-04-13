#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

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
#include <bits/stdc++.h>
struct isBSTReturn{
    int maxLeft, minRight;
    bool isBST;
    int maxHeight = 0;
    isBSTReturn(int maxLeft, int minRight, bool isBST, int ht) {
        this->maxLeft = maxLeft;
        this->minRight = minRight;
        this->isBST = isBST;
        maxHeight = ht;
    }
};

 isBSTReturn isBST(BinaryTreeNode<int>* root) {
    if(!root) {
        isBSTReturn ans(INT_MIN, INT_MAX, true, 0);
        return ans;
    }
    isBSTReturn left = isBST(root->left);
    isBSTReturn right = isBST(root->right);
    bool ok = true;
    if(root->data <= left.maxLeft) ok = false;
    if(root->data > right.minRight) ok = false;
    ok = ok and left.isBST and right.isBST;
    int ht = max(right.maxHeight, left.maxHeight);
    if(ok) ++ht;
    isBSTReturn ans(max(root->data, max(left.maxLeft, right.maxLeft)), min(root->data, min(left.minRight, right.minRight)), ok, ht);
    ans.maxLeft = max(root->data, max(left.maxLeft, right.maxLeft));
    ans.minRight = min(root->data, min(left.minRight, right.minRight));
    ans.isBST = ok;
    ans.maxHeight = ht;
    return ans;
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here
    return isBST(root).maxHeight;
}
BinaryTreeNode<int>* takeInput() {
    int rootData;
    
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
       
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << largestBSTSubtree(root);
    delete root;
}