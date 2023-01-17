#include <bits/stdc++.h>

using namespace std;

int N, A[200000], cache[200000][2];

int solve(int idx) {
    int& ret = cache[idx][0];
    if (ret != -1) return ret;
    ret = solve(idx - 1);
    cache[idx][1] = (A[idx] < cache[idx - 1][1]) ? A[idx] : cache[idx - 1][1];

    return ret = max(ret, A[idx] - cache[idx - 1][1]);
}

int main() {
    memset(cache, -1, sizeof(cache));

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cache[0][0] = 0, cache[0][1] = A[0];

    solve(N - 1);

    for (int i = 0; i < N; i++) {
        cout << cache[i][0] << " ";
    }
}