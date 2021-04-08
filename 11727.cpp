#include <bits/stdc++.h>

using namespace std;

int n, cache[1001];

void initCache() {
    memset(cache, -1, 1001 * sizeof(int));
}

void input() {
    cin >> n;
}

int solve(int pos) {
    if (pos == n + 1) return 1;
    if (pos > n + 1) return 0;

    int& ret = cache[pos];
    if (ret != -1) return ret;
    ret = 0;
    return ret += (solve(pos + 1) + solve(pos + 2) + solve(pos + 2)) % 10007;
}

int main() {
    initCache();
    input();
    cout << solve(1);
}