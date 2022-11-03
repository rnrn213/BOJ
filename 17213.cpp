#include <bits/stdc++.h>

using namespace std;

int N, M, cache[11][31];

int solve(int n, int m) {
    if (n == 0) {
        if (m == 0) return 1;
        else return 0;
    }

    int& ret = cache[n][m];
    if (ret != -1) return ret;
    ret = 0;

    for (int i = 1; i <= m - n + 1; i++) {
        ret += solve(n - 1, m - i);
    }

    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));

    cin >> N >> M;

    cout << solve(N, M);
}