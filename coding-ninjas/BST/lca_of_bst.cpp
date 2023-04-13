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

pair<int, int> getLCAHelper(BinaryTreeNode<int>* root, int val1, int val2) {
    if(!root)
          return { 0, -1 };
    auto left = getLCAHelper(root->left, val1, val2);
    auto right = getLCAHelper(root->right, val1, val2);
    if(val1 == val2 and root->data == val1) return {2, root->data};
    if((root->data == val1 or root->data == val2) and (left.first == 1 or right.first == 1))
          return { 2, root->data };
        if(root->data == val1 or root->data == val2)
          return { 1, -1 };
    
    if(left.first == 2) return {2, left.second};
    if(right.first == 2) return {2, right.second};
    if(left.first == 1 and right.first == 1) return {2, root->data};
    if(left.first == 0 and right.first == 0)
          return { 0, -1 };
    if(left.first == 1 or right.first == 1)
          return { 1, -1 };
    return {0, -1};
}

int getLCA(BinaryTreeNode<int>* root , int val1 , int val2){
    // Write your code here
    return getLCAHelper(root, val1, val2).second;
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
    int a, b;
    cin >> a >> b;
    cout << getLCA(root, a, b);
    delete root;
}