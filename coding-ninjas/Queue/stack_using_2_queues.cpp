#include <iostream>
using namespace std;

#include <bits/stdc++.h>
class Stack {
    // Define the data members
    queue<int> q1, q2;
   public:
    Stack() {
        // Implement the Constructor
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function
        return q1.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function
        return q1.empty();
    }

    void push(int element) {
        // Implement the push() function
        q1.push(element);
    }

    int pop() {
        // Implement the pop() function
        if(isEmpty()) return -1;
        while(q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int ans = q1.front();
        q1.pop();
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
        return ans;
    }

    int top() {
        // Implement the top() function
        if(isEmpty()) return -1;
        while(q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int ans = q1.front();
        q1.pop();
        q2.push(ans);
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
        return ans;
    }
};
int main() {
    Stack st;

    int q;
    cin >> q;

    while (q--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                st.push(input);
                break;
            case 2:
                cout << st.pop() << "\n";
                break;
            case 3:
                cout << st.top() << "\n";
                break;
            case 4:
                cout << st.getSize() << "\n";
                break;
            default:
                cout << ((st.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
}