#include <bits/stdc++.h>

using namespace std;

int N, T, K[100], S[100], cache[100][10001];

int solve(int idx, int time) {
    if (idx == N) return 0;

    int &ret = cache[idx][time];
    if (ret != -1) return ret;

    ret = solve(idx + 1, time);
    if (time >= K[idx])
        ret = max(ret, S[idx] + solve(idx + 1, time - K[idx]));
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));

    cin >> N >> T;
    for (int i = 0; i < N; i++) {
        cin >> K[i] >> S[i];
    }

    cout << solve(0, T);
}