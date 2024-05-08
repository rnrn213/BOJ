#include <bits/stdc++.h>

using namespace std;

int N;
long long dp[1000001];
vector<int> isReceived(1000001, 0);

// int solve(int cnt, int idx)
// {
//     if (idx == N - 1)
//     {
//         if (isReceived[idx]) return 1;
//         else return 0;
//     }

//     int& ret = dp[idx];
//     if (ret != -1) return ret;
//     ret = 0;

//     for (int i = 0; i < N; i++)
//     {
//         if (i == idx) continue;
//         if (!isReceived[i])
//         {
//             isReceived[i] = 1;
//             ret = (ret + solve(cnt + 1, idx + 1)) % 1000000000;
//             isReceived[i] = 0;
//         }
//     }

//     return ret;
// }

int main()
{
    memset(dp, 0, sizeof(dp));

    cin >> N;

    dp[2] = 1;
    for (int i = 3; i <= N; i++)
    {
        dp[i] = ((i - 1) * ((dp[i - 1] + dp[i - 2]) % 1000000000)) % 1000000000;
    }

    cout << dp[N];
}