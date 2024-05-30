#include <bits/stdc++.h>

using namespace std;

int N, M, dp[500][500];
char miro[500][500];

int solve(int y, int x)
{
    if ((y < 0 || x < 0) || (y == N || x == M)) return 1;

    int& ret = dp[y][x];
    if (ret != -1) return ret;
    ret = 0;

    if (miro[y][x] == 'U') ret = solve(y - 1, x);
    if (miro[y][x] == 'R') ret = solve(y, x + 1);
    if (miro[y][x] == 'D') ret = solve(y + 1, x);
    if (miro[y][x] == 'L') ret = solve(y, x - 1);

    return ret;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> miro[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            ans += solve(i, j);
        }
    }
    cout << ans;

}