#include <bits/stdc++.h>

using namespace std;

int N, M, cache[41][2], seat[41];

int solve(int idx, int isSit) {
    if (idx == N)
        return 1;
    
    int& ret = cache[idx][isSit];
    if (ret != -1) return ret;

    if (seat[idx] == idx)
        return ret = solve(idx + 1, 0);

    if (seat[idx] != -1) {
        seat[idx - 1] = idx;
        ret = solve(idx + 1, 0);
        seat[idx - 1] = -1;
    }
    else {
        seat[idx] = idx;
        ret = solve(idx + 1, 0);
        seat[idx] = -1;

        if (seat[idx + 1] == -1) {
            seat[idx + 1] = idx;
            ret += solve(idx + 1, 1);
            seat[idx + 1] = -1;
        }
    }

    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    memset(seat, -1, sizeof(seat));

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int vip;
        cin >> vip;

        seat[vip] = vip;
    }

    cout << solve(1, seat[1] != -1);
}