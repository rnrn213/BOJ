#include <bits/stdc++.h>

using namespace std;

int N, M, cache[3001][3001];
char board[3001][3001];

int solve(int y, int x)
{
    if (y == N && x == M) return 1;

    int& ret = cache[y][x];
    if (ret != -1) return ret;
    ret = 0;

    if (board[y][x] == 'E' || board[y][x] == 'B')
        ret = (ret + solve(y, x + 1)) % 1000000009;
    if (board[y][x] == 'S' || board[y][x] == 'B')
        ret = (ret + solve(y + 1, x)) % 1000000009;

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> board[i][j];
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            ans = (ans + solve(i, j)) % 1000000009;
        }
    }

    cout << ans;
}