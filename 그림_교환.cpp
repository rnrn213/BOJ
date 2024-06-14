#include <bits/stdc++.h>

using namespace std;

int N, dp[16][10][(1 << 17) - 1];
string price[16];

int solve(int idx, int prevPrice, int isVisited)
{
    int& ret = dp[idx][prevPrice][isVisited];
    if (ret != -1) return ret;
    ret = 1;

    for (int i = 0; i < N; i++)
    {
        if (price[idx][i] - '0' >= prevPrice && !(isVisited & (1 << (i + 1))))
        {
            ret = max(ret, 1 + solve(i + 1, price[idx][i] - '0', isVisited | (1 << (i + 1))));
        }
    }

    return ret;
}

int main()
{
    memset(dp, -1, sizeof(dp));

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> price[i];
    }

    cout << solve(1, 0, 1 << 1);
}