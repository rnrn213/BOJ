#include <bits/stdc++.h>

using namespace std;

int N, board[1001][1001], cache[1001][1001][3];

int solve(int y, int x, int prev)
{
    if (y == N || x == N) return 0;

    int& ret = cache[y][x][prev];
    if (ret != -1) return ret;
    ret = max(solve(y + 1, x, prev), solve(y, x + 1, prev));

    if (prev == 0 && board[y][x] == 1) ret = max({ret, 1 + solve(y + 1, x, board[y][x]), 1 + solve(y, x + 1, board[y][x])});
    if (prev == 1 && board[y][x] == 2) ret = max({ret, 1 + solve(y + 1, x, board[y][x]), 1 + solve(y, x + 1, board[y][x])});
    if (prev == 2 && board[y][x] == 0) ret = max({ret, 1 + solve(y + 1, x, board[y][x]), 1 + solve(y, x + 1, board[y][x])});

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

    cout << solve(0, 0, 2);
}