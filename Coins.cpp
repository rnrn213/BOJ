#include "bits/stdc++.h"

using namespace std;

int T, N, C[20], dp[20001][20];

int solve(int m, int idx)
{
    if (m == 0) return 1;
    if (m < 0) return 0;

    int& ret = dp[m][idx];
    if (ret != -1) return ret;
    ret = 0;

    for (int i = idx; i < N; i++)
    {
        ret += solve(m - C[i], i);
    }

    return ret;
}

int main() 
{
    cin >> T;
    for (int tc = 0; tc < T; tc++)
    {
        memset(dp, -1, sizeof(dp));

        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> C[i];
        }

        int M;
        cin >> M;

        cout << solve(M, 0) << "\n";
    }
}