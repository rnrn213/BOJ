#include <bits/stdc++.h>

using namespace std;

const int INF = 2100000000;

int N, D[21][21], dp[21][1 << 21];

int solve(int idx, int mask)
{
    if (idx > N) return 0;

    int& ret = dp[idx][mask];
    if (ret != -1) return ret;
    ret = INF;

    for (int i = 1; i <= N; i++)
    {
        if (mask & (1 << i)) continue;

        ret = min(ret, D[idx][i] + solve(idx + 1, mask | (1 << i)));
    }

    return ret;
}

int main()
{
    memset(dp, -1, sizeof(dp));

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> D[i][j];
        }
    }

    cout << solve(1, 0);
}