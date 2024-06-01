#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N, K, s[100001], nextIdx[100001];
ll dp[100001], pSum[100001], arr[100001];

ll solve(int idx)
{
    if (idx > N) return 0;

    ll& ret = dp[idx];
    if (ret != -1) return ret;

    
    return ret = max(solve(idx + 1), arr[idx] + solve(nextIdx[idx]));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof(dp));

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> s[i];
        pSum[i] = s[i] + pSum[i - 1];
    }

    int start = 0, end = 0;
    ll sum = 0;
    while (start <= end)
    {
        while (end <= N && sum < K)
        {
            sum += s[end];
            end++;
        }
        if (sum >= K) arr[start] = sum - K;
        nextIdx[start] = end;
        sum -= s[start];
        start++;
    }

    cout << solve(1);
}

