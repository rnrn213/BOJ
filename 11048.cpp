#include <bits/stdc++.h>

using namespace std;

int N, M, maze[1001][1001], cache[1001][1001];

int solve(int y, int x) {
    if (y == N && x == M) return maze[y][x];
    if (y > N || x > M) return -2100000000;

    int& ret = cache[y][x];
    if (ret != -1) return ret;
    
    return ret = max({maze[y][x] + solve(y + 1, x), maze[y][x] + solve(y, x + 1), maze[y][x] + solve(y + 1, x + 1)});
}

int main() {
    memset(cache, -1, sizeof(cache));

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> maze[i][j];
        }
    }

    cout << solve(1, 1);
}