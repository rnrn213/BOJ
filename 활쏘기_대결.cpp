#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N, A[200002];
ll dp[200002];
ll v[200002];

int main()
{
    memset(dp, 0, sizeof(dp));

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }

    for (int i = 1; i <= N; i++)
    {
        if (A[i] + v[i - 1] >= dp[i - 1])
        {
            dp[i] = A[i] + v[i - 1];
            v[i] = dp[i - 1];
        }
        else
        {
            dp[i] = dp[i - 1];
            v[i] = v[i - 1] + A[i];
        }
    }

    cout << dp[N];
}