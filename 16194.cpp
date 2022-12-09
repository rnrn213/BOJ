#include <bits/stdc++.h>

using namespace std;

int N, P[1001], cache[1001];

int solve(int num) {
    if (num > N) return 100000000;
    if (num == N) return 0;

    int& ret = cache[num];
    if (ret != -1) return ret;
    ret = 100000000;

    for (int i = 1; i <= N; i++) {
        ret = min(ret, P[i] + solve(num + i));
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(cache, -1, sizeof(cache));

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> P[i];
    }

    cout << solve(0);
}