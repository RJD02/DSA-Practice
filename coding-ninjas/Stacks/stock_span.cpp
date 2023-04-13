#include <iostream>
using namespace std;

int* stockSpan(int *price, int size) {
    int *ans = new int[size];
    ans[0] = 1;
    for(int i = 1; i < size; i++) {
        if(price[i] <= price[i - 1]) ans[i] = 1;
        else {
            ans[i] = ans[i - 1] + 1;
            int j = i - ans[i - 1] - 1;
            while(j >= 0 and price[j--] < price[i]) ans[i]++;
        }
    }
    return ans;
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int *output = stockSpan(input, size);
    for (int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }

    cout << "\n";

    delete[] input;
    delete[] output;
}