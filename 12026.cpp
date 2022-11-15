#include <bits/stdc++.h>

using namespace std;

int N, cache[1001][3], invalid_ans = 123456789;
string street, sidewalkBlock = "BOJ";

int solve(int idx, int turn) {
    if (idx == N - 1) return 0;

    int& ret = cache[idx][turn];
    if (ret != -1) return ret;
    ret = invalid_ans;

    for (int next = idx + 1; next < N; next++) {
        if (street[next] == sidewalkBlock[(turn + 1) % 3]) {
            ret = min(ret, (next - idx) * (next - idx) + solve(next, (turn + 1) % 3));
        }
    }

    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));

    cin >> N >> street;

    int ans = (solve(0, 0) == invalid_ans) ? -1 : solve(0, 0);
    cout << ans;
}