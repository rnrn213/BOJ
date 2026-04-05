#include <bits/stdc++.h>

using namespace std;

int N, A0, B0, M, K, cache[501][1001];

int solve(int idx, int x)
{
    if (idx == N) return 0;

    int& ret = cache[idx][x];
    if (ret != -1) return ret;
    
    int i = K;
    while (B0 + M - x - i >= 0)
    {
        ret = max(ret, (A0 + x - M + i) * (B0 + M - x - i) + solve(idx + 1, x + i));
        i++;
    }
    i = -K;
    while (A0 + x - M + i >= 0)
    {
        ret = max(ret, (A0 + x - M + i) * (B0 + M - x - i) + solve(idx + 1, x + i));
        i--;
    }

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N >> A0 >> B0 >> K;
    M = min(A0, B0);

    cout << solve(0, M);
}
