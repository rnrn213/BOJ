#include <bits/stdc++.h>

using namespace std;

int N, M, arr[101][101], basicCnt = 102, dp[101][101];
vector<bool> isBasic(101, true);

int solve(int idx, int parts)
{
    if (idx == parts) return 1;

    int& ret = dp[idx][parts];
    if (ret != -1) return ret;
    ret = 0;

    for (int i = 1; i <= N; i++)
    {
        if (arr[idx][i] > 0)
        {
            ret += arr[idx][i] * solve(i, parts);
        }
    }

    return ret;
}

int main()
{
    memset(dp, -1, sizeof(dp));

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int X, Y, K;
        cin >> X >> Y >> K;

        arr[X][Y] = K;

        isBasic[X] = false;
    }

    for (int i = 1; i <= N; i++)
    {
        if (isBasic[i])
            cout << i << " " << solve(N, i) << "\n";
    }
}