#include <bits/stdc++.h>

using namespace std;

int N, M, area[301][301], cache[301][301];

void initCache() {
    memset(cache, -1, sizeof(cache));
}

void input() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> area[i][j];
        }
    }
}

int solve(int y, int x) {
    if (y > N || x > M) return 0;

    int& ret = cache[y][x];
    if (ret != -1) return ret;
    return ret = max(area[y][x] + solve(y + 1, x), area[y][x] + solve(y, x + 1));
}

int main() {
    initCache();
    input();
    cout << solve(1, 1);
}