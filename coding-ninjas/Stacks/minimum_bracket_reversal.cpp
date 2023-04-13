#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int countBracketReversals(string ip) {
    if(ip.size() % 2) return -1;
    int leftBrace = 0, rightBrace = 0;
    for(auto i: ip) {
        if(i == '{') leftBrace++;
        else
            if(leftBrace == 0) rightBrace++;
            else leftBrace--;
    }
    int ans = ceil(leftBrace / 2.0) + ceil(rightBrace / 2.0);
    return ans;
}

int main() {
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}