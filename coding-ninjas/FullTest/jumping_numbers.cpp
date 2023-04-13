#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isJumpingNumber(int n) {
    string numStr = to_string(n);
    for (int i = 0; i < numStr.size() - 1; i++) {
        if (abs((int)numStr[i] - (int)numStr[i + 1]) != 1) return false;
    }
    return true;
}

void showJumpingNos(int x) {
    vector<string> result;
    for (int i = 0; i < min(x, 10); i++)
        result.push_back(to_string(i));
    for (int i = 10; i < x + 1; i++) {
        if (isJumpingNumber(i))
            result.push_back(to_string(i));
    }
    sort(result.begin(), result.end(), [ = ](string & a, string & b) {
        if (a[0] == b[0]) {
            if (a.size() != b.size()) return a.size() < b.size();
            int i = 1, j = 1;
            while (i < a.size() and j < b.size()) {
                if (a[i] == b[j]) i++, j++;
                else break;
            }
            return a[i] > b[j];
        }
        return a[0] < b[0];
    });
    for (auto i : result)
        cout << i << " ";
}

void showJumpingNosBFS(int x) {
    vector<string> result;
    deque<int> q;
    for (int i = 1; i <= min(x, 9); i++) q.push_back(i);
    while (!q.empty()) {
        int num = q.front();
        q.pop_front();
        if (num > x) continue;
        result.push_back(to_string(num));
        int lastDigit = num % 10;
        if (lastDigit > 0) q.push_back(num * 10 + lastDigit - 1);
        if (lastDigit < 9) q.push_back(num * 10 + lastDigit + 1);
    }
    result.push_back(to_string(0));
    sort(result.begin(), result.end(), [ = ](string & a, string & b) {
        if (a[0] == b[0]) {
            if (a.size() != b.size()) return a.size() < b.size();
            int i = 1, j = 1;
            while (i < a.size() and j < b.size()) {
                if (a[i] == b[j]) i++, j++;
                else break;
            }
            return a[i] > b[j];
        }
        return a[0] < b[0];
    });
    for (auto i : result)
        cout << i << " ";
}

int main() {
    int x;
    cin >> x;
    showJumpingNosBFS(x);
}
