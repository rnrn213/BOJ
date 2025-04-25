#include <bits/stdc++.h>

using namespace std;

int N, board[101][101], cache[101][101];

int solve(int y, int x)
{
    if (y == N - 1 && x == N - 1) return 1;

    int& ret = cache[y][x];
    if (ret != -1) return ret;
    ret = 1;

    for (int nextY = y; nextY < N; nextY++)
    {
        for (int nextX = x; nextX < N; nextX++)
        {
            if (nextY == y && nextX == x) continue;

            if (board[y][x] < board[nextY][nextX])
                ret = max(ret, 1 + solve(nextY, nextX));
        }
    }

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            ans = max(ans, solve(i, j));
        }
    }
    cout << ans;
}