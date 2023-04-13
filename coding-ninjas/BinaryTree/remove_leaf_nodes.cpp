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
};

using namespace std;

bool isLeaf(BinaryTreeNode<int>* root) {
    return root->left == root->right;
}

BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int>* root) {
    if(!root) return NULL;
    if(isLeaf(root)) return NULL;
    root->left = removeLeafNodes(root->left);
    root->right = removeLeafNodes(root->right);
    return root;
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

void inOrder(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return;
    }

    inOrder(root->left);

    cout << root->data << " ";
    
    inOrder(root->right);

}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    root = removeLeafNodes(root);
    inOrder(root);
}