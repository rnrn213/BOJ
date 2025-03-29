#include <bits/stdc++.h>

using namespace std;

int T, k, p[101], n[101], cache[10001][101];

int solve(int m, int idx)
{
    if (m == 0) return 1;
    if (idx == k) return 0;

    int& ret = cache[m][idx];
    if (ret != -1) return ret;
    ret = 0;
    
    for (int i = 0; i <= n[idx]; i++)
    {
        if (p[idx] * i > m) break;

        ret += solve(m - (p[idx] * i), idx + 1);
    }

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> T >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> p[i] >> n[i];
    }

    cout << solve(T, 0);
}