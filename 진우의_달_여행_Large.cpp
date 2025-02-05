#include <bits/stdc++.h>

using namespace std;

int N, M, board[1001][1001], cache[1001][1001][4];

int solve(int y, int x, int prev)
{
    if (y == N) return 0;

    int& ret = cache[y][x][prev];
    if (ret != -1) return ret;
    ret = 1000000000;

    if (prev != 0 && x - 1 >= 0)
        ret = min(ret, board[y][x] + solve(y + 1, x - 1, 0));
    if (prev != 1)
        ret = min(ret, board[y][x] + solve(y + 1, x, 1));
    if (prev != 2 && x + 1 < M)
        ret = min(ret, board[y][x] + solve(y + 1, x + 1, 2));
    
    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }

    int ans = 1000000000;
    for (int i = 0; i < M; i++)
    {
        ans = min(ans, solve(0, i, 3));
    }
    cout << ans;
}