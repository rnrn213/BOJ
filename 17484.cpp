#include <bits/stdc++.h>

using namespace std;

int N, M;

int travel(const vector< vector<int> >& space, int y, int x, int prev) {
    if (x < 0 || x >= M) return 10000000;
    if (y == N) return 0;

    int ret = 10000000;
    for (int i = -1; i <= 1; i++) {
        if (i == prev) continue;

        ret = min(ret, space[y][x] + travel(space, y + 1, x + i, i));
    }

    return ret;
}

int solve(const vector< vector<int> >& space) {
    int ret = 10000000;
    for (int i = 0; i < M; i++) {
        ret = min(ret, travel(space, 0, i, 2));
    }
    return ret;
}

int main() {
    cin >> N >> M;
    vector< vector<int> > space(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> space[i][j];
        }
    }

    cout << solve(space);
}