#include <bits/stdc++.h>

using namespace std;

vector< pair<int, int> > counsels;
int cache[16];
int N;

void initCache() {
    memset(cache, -1, 16 * sizeof(int));
}

void input() {
    cin >> N;

    int T, P;
    for (int i = 0; i < N; i++) {
        cin >> T >> P;
        counsels.push_back(make_pair(T, P));
    }
}

int solve(int t) {
    if (t == N + 1) return 0;

    int& ret = cache[t];
    if (ret != -1) return ret;
    ret = solve(t + 1);
    if (t + counsels[t - 1].first <= N + 1) ret = max(ret, counsels[t - 1].second + solve(t + counsels[t - 1].first));
    return ret;
}

int main() {
    initCache();
    input();
    cout << solve(1);
}