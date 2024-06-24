#include <bits/stdc++.h>

using namespace std;

int N, stone[2501], dp[2501][2501];

int solve(int idx, int cnt, int st)
{
    if (idx == N)
    {
        if (st == stone[N]) return 0;
        return 1;
    }

    int& ret = dp[idx][cnt];
    if (ret != -1) return ret;

    if (stone[idx] - st == 0) return ret = solve(idx + 1, 0, 0);

    ret = 1 + solve(idx + 1, 0, 0);
    if (stone[idx] - st > stone[idx + 1])
    {
        ret = min(ret, 2 + solve(idx + 1, 0, stone[idx + 1]));
    }
    else
    {
        ret = min(ret, 1 + solve(idx + 1, cnt + 1, stone[idx] - st));
    }

    return ret;
}

int main()
{
    memset(dp, -1, sizeof(dp));

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> stone[i];
    }

    cout << solve(1, 0, 0);
}