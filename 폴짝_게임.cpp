#include <bits/stdc++.h>

using namespace std;

const int INF = -2100000000;

int N, M, D;
vector<vector<int>> board, cache;

int solve(int y, int x)
{
    if (y == N) return 0;

    int& ret = cache[y][x];
    if (ret != INF) return ret;

    for (int i = 1; i <= D; i++)
    {
        if (y + i > N) break;
        for (int j = 0; j <= D - i; j++)
        {
            if (x - j > 0)
                ret = max(ret, board[y][x] * board[y + i][x - j] + solve(y + i, x - j));
            if (x + j <= M)
                ret = max(ret, board[y][x] * board[y + i][x + j] + solve(y + i, x + j));
        }
    }

    return ret;
}

int main()
{
    cin >> N >> M >> D;
    board = vector<vector<int>>(N + 1, vector<int>(M + 1, 0));
    cache = vector<vector<int>>(N + 1, vector<int>(M + 1, INF));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> board[i][j];
        }
    }

    int ans = INF;
    for (int i = 1; i <= M; i++)
    {
        ans = max(ans, solve(1, i));
    }

    cout << ans;
}