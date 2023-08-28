#include <bits/stdc++.h>

using namespace std;

int N, h[17][17], cache[17][17][3];
int dx[3] = {1, 1, 0};
int dy[3] = {0, 1, 1};

int solve(int y, int x, int prev) {
    if (y == N && x == N) return 1;

    int& ret = cache[y][x][prev];
    if (ret != -1) return ret;
    ret = 0;

    if (prev == 0) {
        if (x + 1 <= N && h[y][x + 1] == 0)
            ret += solve(y, x + 1, 0);
        if (y + 1 <= N && x + 1 <= N && 
              h[y + 1][x] == 0 && h[y + 1][x + 1] == 0 && h[y][x + 1] == 0)
            ret += solve(y + 1, x + 1, 1);
    }
    if (prev == 1) {
        if (x + 1 <= N && h[y][x + 1] == 0)
            ret += solve(y, x + 1, 0);
        if (y + 1 <= N && x + 1 <= N && 
              h[y + 1][x] == 0 && h[y + 1][x + 1] == 0 && h[y][x + 1] == 0)
            ret += solve(y + 1, x + 1, 1);
        if (y + 1 <= N && h[y + 1][x] == 0)
            ret += solve(y + 1, x, 2);
    }
    if (prev == 2) {
        if (y + 1 <= N && x + 1 <= N && 
              h[y + 1][x] == 0 && h[y + 1][x + 1] == 0 && h[y][x + 1] == 0)
            ret += solve(y + 1, x + 1, 1);
        if (y + 1 <= N && h[y + 1][x] == 0)
            ret += solve(y + 1, x, 2);
    }

    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> h[i][j];
        }
    }

    cout << solve(1, 2, 0);
}