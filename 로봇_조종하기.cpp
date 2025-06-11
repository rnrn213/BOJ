#include <bits/stdc++.h>

using namespace std;

const int INF = -123456789;

int N, M, board[1001][1001], cache[1001][1001][3];

void initCache()
{
    for (int i = 0; i < 1001; i++)
    {
        for (int j = 0; j < 1001; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                cache[i][j][k] = INF;
            }
        }
    }
}

int isValid(int y, int x)
{
    return (y >= 1 && y <= N) && (x >= 1 && x <= M);
}

int solve(int y, int x, int prev)
{
    if (y == N && x == M) return board[y][x];

    int& ret = cache[y][x][prev];
    if (ret != INF) return ret;
    
    int nextY, nextX;
    //
    nextY = y + 1; nextX = x;
    if (isValid(nextY, nextX))
        ret = max(ret, board[y][x] + solve(nextY, nextX, 0));
    //
    nextY = y; nextX = x - 1;
    if (isValid(nextY, nextX) && prev != 2)
        ret = max(ret, board[y][x] + solve(nextY, nextX, 1));
    //
    nextY = y; nextX = x + 1;
    if (isValid(nextY, nextX) && prev != 1)
        ret = max(ret, board[y][x] + solve(nextY, nextX, 2));

    return ret;
}

int main()
{
    initCache();

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> board[i][j];
        }
    }

    cout << solve(1, 1, 0);
}