#include <iostream>
#include <queue>

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

    ~BinaryTreeNode() {
    	if(left) 
       		delete left;
    	if(right) 
       		delete right;
    }
};

using namespace std;

void printKDistanceNodeDown(BinaryTreeNode<int>* root, int k) {
        if(!root or k < 0) return ;
        if(k == 0) {
                cout << root->data << endl;
                return ;
        }
        printKDistanceNodeDown(root->left, k - 1);
        printKDistanceNodeDown(root->right, k - 1);
}

int printKDistanceNodes(BinaryTreeNode<int>* root, int node, int k) {
        if(!root) return -1;
        if(root->data == node) {
                printKDistanceNodeDown(root, k);
                return 0;
        }
        int dl = printKDistanceNodes(root->left, node, k);
        if(dl != -1) {
                if(dl + 1 == k) cout << root->data << endl;
                else printKDistanceNodeDown(root->right, k - dl - 2);
                return 1 + dl;
        }
        int dr = printKDistanceNodes(root->right, node, k);
        if(dr != -1) {
                if(dr + 1 == k) cout << root->data << endl;
                else printKDistanceNodeDown(root->left, k - dr - 2);
                return 1 + dr;
        }
        return -1;
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    // Write your code herez
    printKDistanceNodes(root, node, k);
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int targetNode, k;
    cin >> targetNode >> k;
    nodesAtDistanceK(root, targetNode, k);
    delete root;
}