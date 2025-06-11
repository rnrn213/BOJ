#include <bits/stdc++.h>

using namespace std;

const int INF = 1000000001;

int n, m, cache[1001][1001], arr[2][1001];

int solve(int idx0, int idx1)
{
    if (n <= m)
    {
        if (idx0 == n) return 0;
        if (idx1 == m) return INF;
    }
    if (n > m)
    {
        if (idx0 == m) return 0;
        if (idx1 == n) return INF;
    }

    int& ret = cache[idx0][idx1];
    if (ret != -1) return ret;
    ret = solve(idx0, idx1 + 1);

    return ret = min(ret, abs(arr[0][idx0] - arr[1][idx1]) + solve(idx0 + 1, idx1 + 1));
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        if (n <= m)
            cin >> arr[0][i];
        else
            cin >> arr[1][i];
    }
    for (int i = 0; i < m; i++)
    {
        if (n <= m)
            cin >> arr[1][i];
        else
            cin >> arr[0][i];
    }

    if (n <= m)
    {
        sort(arr[0], arr[0] + n);
        sort(arr[1], arr[1] + m);
    }
    else
    {
        sort(arr[0], arr[0] + m);
        sort(arr[1], arr[1] + n);
    }

    cout << solve(0, 0);
}