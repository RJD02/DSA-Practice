#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string expression) {
    stack<char> st;
    for(auto i: expression) {
        if(!st.empty() and i == ')') st.pop();
        else if(st.empty() and i == ')') return false;
        else st.push(i);
    }
    if(st.size() != 0) return false;
    return true;
}

int main() 
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}