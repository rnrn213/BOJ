#include <bits/stdc++.h>

using namespace std;

int N, K, cache[100][100001];
vector< vector<int> > WV;

bool cmp(vector<int> a, vector<int> b) {
    return ((double)a[1] / a[0]) > ((double)b[1] / b[0]);
}

int solve(int idx, int w) {
    if (idx == N) return 0;

    int& ret = cache[idx][w];
    if (ret != -1) return ret;
    ret = solve(idx + 1, w);

    if (w + WV[idx][0] <= K) {
        ret = max(ret, WV[idx][1] + solve(idx + 1, w + WV[idx][0]));
    }

    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        WV.push_back(vector<int>(2));
        cin >> WV[i][0] >> WV[i][1];
    }

    sort(WV.begin(), WV.end(), cmp);

    cout << solve(0, 0);
}