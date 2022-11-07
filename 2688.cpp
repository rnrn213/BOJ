#include <bits/stdc++.h>

using namespace std;

int T, n;
long long cache[65][10];

long long solve(int idx, int num) {
    if (idx == n - 1) return 1;

    long long& ret = cache[idx + 1][num];
    if (ret != -1) return ret;
    ret = 0;

    for (int i = num; i < 10; i++) {
        ret += solve(idx + 1, i);
    }

    return ret;
}

int main() {
    cin >> T;

    for (int i = 0; i < T; i++) {
        memset(cache, -1, sizeof(cache));

        cin >> n;

        cout << solve(-1, 0) << "\n";
    }
}