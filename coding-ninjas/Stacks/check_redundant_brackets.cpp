#include <bits/stdc++.h>
using namespace std;

bool checkRedundantBrackets(string expression) {
    stack<int> st;
    int count = 0;
    for(auto i: expression) {
        if(i == '(') {
            st.push(count);
            count = 0;
        } else if(i == ')') {
            if(count < 2) return true;
            count = st.top();
            st.pop();
        } else {
            count++;
        }
    }
    return false;
}

int main() {
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}