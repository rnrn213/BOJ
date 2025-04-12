#include <bits/stdc++.h>

using namespace std;

int M, N, board[501][501], cache[501][501][1 << 4];
vector<vector<bool>> visited(501, vector<bool>(501, false));

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int solve(int y, int x)
{
    if (y == M - 1 && x == N - 1) return 1;

    int state = 0;
    for (int i = 0; i < 4; i++)
    {
        int nextY = y + dy[i], nextX = x + dx[i];
        if ((nextY < 0 || nextY == M) || (nextX < 0 || nextX == N)) continue;
        if (visited[nextY][nextX])
            state |= (1 << i);
    }
    int& ret = cache[y][x][state];
    if (ret != -1) return ret;
    ret = 0;

    visited[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int nextY = y + dy[i], nextX = x + dx[i];
        if ((nextY < 0 || nextY == M) || (nextX < 0 || nextX == N)) continue;
        if (board[nextY][nextX] < board[y][x] && !visited[nextY][nextX])
        {
            ret += solve(nextY, nextX);
        }
    }
    visited[y][x] = false;

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> M >> N;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    cout << solve(0, 0);
}