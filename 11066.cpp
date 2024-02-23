#include <bits/stdc++.h>

using namespace std;

int T, K, files[501], dp[501][501], sum[501];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int tc = 0; tc < T; tc++)
    {
        for (int i = 1; i <= 500; i++)
        {
            for (int j = 1; j <= 500; j++)
            {
                if (i == j) dp[i][j] = 0;
                else dp[i][j] = 2100000000;
            }
        }

        cin >> K;
        for (int i = 1; i <= K; i++)
        {
            cin >> files[i];
            sum[i] = sum[i - 1] + files[i];
        }

        for (int i = 1; i < K; i++)
        {
            for (int j = 1; j + i <= K; j++)
            {
                for (int k = j; k < j + i; k++)
                {
                    dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] + sum[j + i] - sum[j - 1]);
                }
            }
        }

        cout << dp[1][K] << '\n';
    }
}