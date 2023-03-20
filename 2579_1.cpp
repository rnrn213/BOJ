#include <bits/stdc++.h>

using namespace std;

int N, stairs[301], cache[301][2];

int solve(int i, int stepped) {
    if (i == N) return stairs[N];

    int& ret = cache[i][stepped];
    if (ret != -1) return ret;

    if (i == 0) ret = solve(1, 0);
    else if (!stepped) ret = stairs[i] + solve(i + 1, 1);

    if (i + 2 <= N) ret = max(ret, stairs[i] + solve(i + 2, 0));

    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> stairs[i];
    }

    cout << solve(0, 0);
}