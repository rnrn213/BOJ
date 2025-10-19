#include <bits/stdc++.h>

using namespace std;

int N, M, cache[1001][1001];
char board[1001][1001];

int dy[] = {-1, 0, 1};
int dx[] = {1, 1, 1};

const int INF = -1000001;

int solve(int y, int x)
{
    if (x == M - 1) return (board[y][x] == 'O') ? 0 : INF;

    int& ret = cache[y][x];
    if (ret != -1) return ret;
    ret = INF;
    
    if (board[y][x] == 'O') ret = 0;
    int carrot = (board[y][x] == 'C') ? 1 : 0;
    for (int i = 0; i < 3; i++)
    {
        int nextY = y + dy[i], nextX = x + dx[i];
        if ((nextY >= 0 && nextY < N) && (nextX >= 0 && nextX < M) && board[nextY][nextX] != '#')
        {
            ret = max(ret, carrot + solve(nextY, nextX));
        }
    }

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));
    cin >> N >> M;
    int sy, sx;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0 ; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'R')
            {
                sy = i; sx = j;
            }
        }
    }

    int ans = solve(sy, sx);
    if (ans < 0) ans = -1;
    cout << ans;
}
