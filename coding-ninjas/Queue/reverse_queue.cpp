#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void reverseQueue(queue<int> &input) {
    vector<int> v;
    while(input.size() != 1) {
        v.push_back(input.front());
        input.pop();
    }
    for(int i = v.size() - 1; i >= 0; i--) {
        input.push(v[i]);
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        queue<int> q;
        int size;
        cin >> size;

        for (int i = 0, val; i < size; i++) {
            cin >> val;
            q.push(val);
        }

        reverseQueue(q);
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }

        cout << "\n";
    }
}