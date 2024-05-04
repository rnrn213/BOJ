#include "bits/stdc++.h"

using namespace std;

int N, h[1001][3], dp[1001][3][3];

int solve(int idx, int color, int firstHomeColor)
{
    if (idx == N)
    {
        if (color == firstHomeColor) return 100000000;
        else return h[idx][color];
    }

    int& ret = dp[idx][color][firstHomeColor];
    if (ret != -1) return ret;
    ret = 2100000000;

    for (int i = 0; i < 3; i++)
    {
        if (i == color) continue;
        ret = min(ret, h[idx][color] + solve(idx + 1, i, firstHomeColor));
    }

    return ret;
}

int main()
{
    memset(dp, -1, sizeof(dp));

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> h[i][0] >> h[i][1] >> h[i][2];
    }
    int ans = min(min(solve(1, 0, 0), solve(1, 1, 1)), solve(1, 2, 2));
    cout << ans;
}