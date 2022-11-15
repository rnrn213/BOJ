#include <bits/stdc++.h>

using namespace std;

int N, P[1001], cache[1001];

int solve(int cards) {
    if (cards == N) return 0;

    int& ret = cache[cards];
    if (ret != -1) return ret;

    for (int i = 1; i + cards <= N; i++) {
        ret = max(ret, P[i] + solve(cards + i));
    }

    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> P[i];
    }

    cout << solve(0);
}