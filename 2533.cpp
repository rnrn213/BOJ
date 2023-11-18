#include <bits/stdc++.h>

using namespace std;

const int INIT_VALUE = 2000000000;
const int MAX = 1900000000;

int N, cache[1000001][2];
vector< vector<int> > f(1000001);
vector<bool> isVisited(1000001, false);

int solve(int idx, int isAA) {
    if (f[idx].size() == 0) return isAA;

    int &ret = cache[idx][isAA];
    if (ret != INIT_VALUE) return ret;
    ret = isAA;

    if (isAA) {
        for (int i = 0; i < f[idx].size(); i++) {
            if (!isVisited[f[idx][i]]) {
                isVisited[f[idx][i]] = true;
                ret += min(solve(f[idx][i], 0), solve(f[idx][i], 1));
                isVisited[f[idx][i]] = false;
            }
        }
    }
    else {
        for (int i = 0; i < f[idx].size(); i++) {
            if (!isVisited[f[idx][i]]) {
                isVisited[f[idx][i]] = true;
                ret += solve(f[idx][i], 1);
                isVisited[f[idx][i]] = false;
            }
        }
    }

    return ret;
}

int main() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        f[u].push_back(v);
        f[v].push_back(u);
    }

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j < 2; j++) {
            cache[i][j] = INIT_VALUE;
        }
    }

    isVisited[1] = true;
    cout << min(solve(1, 0), solve(1, 1));
}