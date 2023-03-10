#include <bits/stdc++.h>

using namespace std;

int N, cache[101][10];

int solve(int idx, int value) {
    if (idx == N) {
        if (value == 0) return 0;
        return 1;
    }

    int& ret = cache[idx][value];
    if (ret != -1) return ret;
    ret = 0;

    if (value > 0) ret = (ret + solve(idx + 1, value - 1)) % 1000000000;
    if (value < 9) ret = (ret + solve(idx + 1, value + 1)) % 1000000000;

    return ret;
}

int solve() {
    int ret = 0;
    for (int i = 0; i < 10; i++) {
        ret = (ret + solve(1, i)) % 1000000000;
    }
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));

    cin >> N;

    cout << solve();
}