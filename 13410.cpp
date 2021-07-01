#include <bits/stdc++.h>

using namespace std;

int reverseNum(int num) {
    vector<int> numV;
    while (num) {
        numV.push_back(num % 10);
        num /= 10;
    }
    int i = 0, ret = 0;
    while (numV.size()) {
        ret += *(numV.end() - 1) * pow(10, i);
        numV.pop_back();
        i++;
    }
    return ret;
}

int main() {
    int N, K, ans = 0;
    cin >> N >> K;
    for (int i = 1; i <= K; i++) {
        int reverse = reverseNum(N * i);
        if (ans < reverse) ans = reverse;
    }
    cout << ans;
}