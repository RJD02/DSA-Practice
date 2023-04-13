#include <iostream>
using namespace std;

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

class BST {
    // Define the data members
    BinaryTreeNode<int>* root;
    int size = 0;
public:
    BST() {
        // Implement the Constructor
    }

    /*----------------- Public Functions of BST -----------------*/

    BinaryTreeNode<int>* minValNode(BinaryTreeNode<int>* root) {
        BinaryTreeNode<int>* curr = root;
        while(curr and curr->left) curr = curr->left;
        return curr;
    }

    BinaryTreeNode<int>* removeUtil(BinaryTreeNode<int>* root, int data) {
        if(!root) return root;
        if(data < root->data)
            root->left = removeUtil(root->left, data);
        else if(data > root->data)
            root->right = removeUtil(root->right, data);
        else {
            if(root->left == root->right) return NULL;
            else if(!root->left) {
                BinaryTreeNode<int>* temp = root->right;
                return temp;
            } else if(!root->right) {
                BinaryTreeNode<int>* temp = root->left;
                return temp;
            }
            BinaryTreeNode<int>* temp = minValNode(root->right);
            root->data = temp->data;
            root->right = removeUtil(root->right, temp->data);
        }
        return root;
    }

    void remove(int data) {
        // Implement the remove() function
        root = removeUtil(root, data);
    }
    void printUtil(BinaryTreeNode<int>* root) {
        if (!root) return;
        cout << root->data << ":";
        if (root->left) cout << "L:" << root->left->data << ",";
        if (root->right) cout << "R:" << root->right->data;
        cout << endl;
        printUtil(root->left);
        printUtil(root->right);
    }
    void print() {
        // Implement the print() function
        printUtil(root);
    }

    void insertUtil(BinaryTreeNode<int>* root, int data, BinaryTreeNode<int>* parent = NULL) {
        BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
        if(!root and !parent) {
            root = newNode;
            return ;
        }
        if(!root) {
            if(parent->data < data) parent->right = newNode;
            else parent->left = newNode;
            return ;
        }
        if(data <= root->data) insertUtil(root->left, data, root);
        else insertUtil(root->right, data, root);
    }

    void insert(int data) {
        // Implement the insert() function
        insertUtil(root, data);
    }
    bool searchUtil(BinaryTreeNode<int>* root, int data) {
        if (!root) return false;
        if (root->data == data) return true;
        if (root->data < data) return searchUtil(root->right, data);
        return searchUtil(root->left, data);
    }
    bool search(int data) {
        // Implement the search() function
        return searchUtil(root, data);
    }
};

int main() {
    BST *tree = new BST();
    int choice, input, q;
    cin >> q;
    while (q--) {
        cin >> choice;
        switch (choice) {
        case 1:
            cin >> input;
            tree->insert(input);
            break;
        case 2:
            cin >> input;
            tree->remove(input);
            break;
        case 3:
            cin >> input;
            cout << ((tree->search(input)) ? "true\n" : "false\n");
            break;
        default:
            tree->print();
            break;
        }
    }
}