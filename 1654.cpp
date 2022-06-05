#include <bits/stdc++.h>

using namespace std;

int main() {
    int K, N;
    cin >> K >> N;

    vector<int> lines(K);
    int maxLength = 0;
    for (int i = 0; i < K; i++) {
        cin >> lines[i];
        if (lines[i] > maxLength)
            maxLength = lines[i];
    }

    long long start = 1, end = maxLength;
    while (start + 1 < end) {
        long long mid = (start + end) / 2, cnt = 0;

        for (int i = 0; i < K; i++) {
            cnt += lines[i] / mid;
        }

        if (cnt >= N) {
            start = mid;
        }
        else
            end = mid;
    }

    int cnt = 0;
    for (int i = 0; i < K; i++) {
        cnt += lines[i] / end;
    }
    if (cnt >= N)
        start = end;

    cout << start;
}