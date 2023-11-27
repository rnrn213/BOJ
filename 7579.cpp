#include <bits/stdc++.h>

using namespace std;

int N, M, m[100], c[100], cache[10001], csum = 0;

int solve() {
    for (int i = 0; i < N; i++) {
        for (int j = csum; j >= c[i]; j--) {
            cache[j] = max(cache[j], cache[j - c[i]] + m[i]);
        }
    }

    for (int i = 0; i <= csum; i++) {
        if (cache[i] >= M) return i;
    }

    return -1;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> m[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> c[i];
        csum += c[i];
    }

    cout << solve();
}