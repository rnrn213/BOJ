#include <bits/stdc++.h>

using namespace std;

int N, M, Q, board[2001][2001], cache[2001][2001];

int solve(int y, int x)
{
    if (y == 0 || x == 0) return 0;

    int& ret = cache[y][x];
    if (ret != -1) return ret;

    return ret = board[y][x] + solve(y - 1, x - 1);
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    memset(cache, -1, sizeof(cache));

    cin >> N >> M >> Q;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> board[i][j];
            board[i][j] += board[i - 1][j];
        }
    }

    for (int i = 0; i < Q; i++)
    {
        int w, p;
        cin >> w >> p;

        cout << solve(w, p) << "\n";
    }
}