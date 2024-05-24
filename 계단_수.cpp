#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000*1000*1000;

int N, dp[101][1 << 10][10];

int solve(int idx, int mask, int prev)
{
    if (idx == N)
    {
        return (mask == ((1 << 10) - 1)) ? 1 : 0;
    }

    int& ret = dp[idx][mask][prev];
    if (ret != -1) return ret;
    ret = 0;

    if (idx == 0)
    {
        for (int i = 1; i < 10; i++)
        {
            ret = (ret + solve(idx + 1, mask | (1 << i), i)) % MOD;
        }
    }
    else
    {
        if (prev > 0)
        {
            ret = (ret + solve(idx + 1, mask | (1 << prev - 1), prev - 1)) % MOD;
        }
        if (prev < 9)
        {
            ret = (ret + solve(idx + 1, mask | (1 << prev + 1), prev + 1)) % MOD;
        }
    }

    return ret;
}

int main()
{
    memset(dp, -1, sizeof(dp));

    cin >> N;

    cout << solve(0, 0, 0);
}