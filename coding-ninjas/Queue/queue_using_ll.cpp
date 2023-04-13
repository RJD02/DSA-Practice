#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

/************************************************************
 
    Following is the structure of the node class 
 
    class Node {
        public :
        int data;
        Node *next;

        Node(int data) {
            this->data = data;
            next = NULL;
        }
    };

**************************************************************/

class Queue {
    // Define the data members
    Node* frontNode = NULL;
    Node* rearNode = NULL;
    int size = 0;
   public:
    Queue() {
        // Implement the Constructor
    }
    
    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function
        return size;
    }

    bool isEmpty() {
        // Implement the isEmpty() function
        return size == 0;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        Node* newNode = new Node(data);
        size++;
        if(isEmpty()) {
            frontNode = newNode;
            rearNode = frontNode;
            return;
        }
        rearNode->next = newNode;
        rearNode = rearNode->next;
        
    }

    int dequeue() {
        // Implement the dequeue() function
        if(isEmpty()) return -1;
        int val = frontNode->data;
        frontNode = frontNode->next;
        size--;

        return val;
    }

    int front() {
        // Implement the front() function
        if(isEmpty()) return -1;
        return frontNode->data;
    }
};

int main() {
    Queue q;

    int t;
    cin >> t;

    while (t--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                q.enqueue(input);
                break;
            case 2:
                cout << q.dequeue() << "\n";
                break;
            case 3:
                cout << q.front() << "\n";
                break;
            case 4:
                cout << q.getSize() << "\n";
                break;
            default:
                cout << ((q.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
}