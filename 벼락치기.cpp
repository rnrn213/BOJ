#include <bits/stdc++.h>

using namespace std;

int N, T, d[1001], m[1001], cache[1001][1001];

int solve(int idx, int days)
{
    if (idx > N) return 0;

    int& ret = cache[idx][days];
    if (ret != -1) return ret;
    ret = 2100000000;

    if (days >= d[idx])
        ret = solve(idx + 1, days - d[idx]);

    return ret = min(ret, m[idx] + solve(idx + 1, days));
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N >> T;
    for (int i = 1; i <= N; i++)
    {
        cin >> d[i] >> m[i];
    }

    cout << solve(1, T);
}