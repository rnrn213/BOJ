#include <bits/stdc++.h>

using namespace std;

int N, M, K, Q, dp[301][301][2];
char board[301][301];

int solve(int x, int y, int turn)
{
    if (x == N && y == M) return (turn + 1) % 2;

    int& ret = dp[x][y][turn % 2];
    if (ret != -1) return ret;

    if (turn % 2 == 0)
    {
        ret = 100000;
        if (x + 1 <= N && board[x + 1][y] == '.')
        {
            ret = min(ret, solve(x + 1, y, turn + 1));
        }
        if (y + 1 <= M && board[x][y + 1] == '.')
        {
            ret = min(ret, solve(x, y + 1, turn + 1));
        }
        for (int i = 1; i <= K; i++)
        {
            if (x + i <= N && y + i <= M)
            {
                if (board[x + i][y + i] == '#') continue;
                ret = min(ret, solve(x + i, y + i, turn + 1));
            }
        }
    }
    else
    {
        if (x + 1 <= N && board[x + 1][y] == '.')
        {
            ret = max(ret, solve(x + 1, y, turn + 1));
        }
        if (y + 1 <= M && board[x][y + 1] == '.')
        {
            ret = max(ret, solve(x, y + 1, turn + 1));
        }
        for (int i = 1; i <= K; i++)
        {
            if (x + i <= N && y + i <= M)
            {
                if (board[x + i][y + i] == '#') continue;
                ret = max(ret, solve(x + i, y + i, turn + 1));
            }
        }
    }

    return ret;
}

int main()
{
    memset(dp, -1, sizeof(dp));

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> board[i][j];
        }
    }
    
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int x, y;
        cin >> x >> y;

        if (solve(x, y, 0) == 0) cout << "First\n";
        else cout << "Second\n";
    }
}