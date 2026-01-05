#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int N, M, K, a[11], t[101], cache[101][1001];

int solve(int idx, int r)
{
    if (idx == M) return (r == 0) ? 1 : 0;

    int& ret = cache[idx][r];
    if (ret != -1) return ret;
    ret = 0;

    for (int i = 0; i < N; i++)
    {
        if (idx == M - 1 && a[i] == 0) continue;
        int remain = ((a[i] % K) * t[idx]) % K;
        ret = (ret + solve(idx + 1, (r + remain) % K)) % MOD;
    }

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N >> M >> K;
    t[0] = 1;
    for (int i = 1; i < M; i++)
    {
        t[i] = ((10 % K) * t[i - 1]) % K;
    }
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    
    cout << solve(0, 0);
}
