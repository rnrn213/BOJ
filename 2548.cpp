#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> cnt(10001, 0);
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        cnt[num]++;
    }

    int minDiffSum = 1000000000, rnn;
    for (int n = 1; n <= 10000; n++) {
        int diffSum = 0;
        for (int i = 1; i <= 10000; i++) {
            diffSum += abs(n - i) * cnt[i];
        }

        if (diffSum < minDiffSum) {
            minDiffSum = diffSum;
            rnn = n;
        }
    }

    cout << rnn;
}