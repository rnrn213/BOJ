#include <bits/stdc++.h>

using namespace std;

int N;
long long dp[1000001];

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