#include <bits/stdc++.h>

using namespace std;

int N, S, M, cache[50][1001];
vector<int> V;

void initCache() {
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 1000; j++) {
            cache[i][j] = -2;
        }
    }
}

int solve(int idx, int volume) {
    if (volume > M || volume < 0)
        return -1;
    if (idx == N)
        return volume;
    
    int &ret = cache[idx][volume];
    if (ret != -2)
        return ret;

    return ret = max(solve(idx + 1, volume + V[idx]), solve(idx + 1, volume - V[idx]));
}

int main() {
    initCache();
    cin >> N >> S >> M;
    V = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }

    cout << solve(0, S);
}