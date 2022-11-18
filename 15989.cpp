#include <bits/stdc++.h>

using namespace std;

int T, n, cache[10001][4];

int solve(int num, int prev) {
    if (num == 0) return 1;
    if (num < 0) return 0;

    int& ret = cache[num][prev];
    if (ret != -1) return ret;
    ret = 0;

    for (int next = prev; next <= 3; next++) {
        ret += solve(num - next, next);
    }

    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));

    solve(10000, 1);

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n;

        cout << cache[n][1] << "\n";
    }
}