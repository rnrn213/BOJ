#include <bits/stdc++.h>

using namespace std;

int N, a[200001], b[200001], ps[200001], cache[200001][2];

int solve(int idx, int s)
{
    if (idx == N)
        return (b[idx] == 1) ? 0 : a[idx];

    int& ret = cache[idx][s];
    if (ret != -1) return ret;
    ret = 0;

    if (s == 0)
    {
        int num = (b[idx] == 1) ? a[idx] : 0;
        ret = num + max(solve(idx + 1, 0), solve(idx + 1, 1));
    }
    if (s == 1)
    {
        int num = (b[idx] == 1) ? 0 : a[idx];
        ret = num + max(ps[N] - ps[idx], solve(idx + 1, 1));
    }

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> b[i];
        ps[i] = ps[i - 1];
        if (b[i])
            ps[i] += a[i];
    }

    cout << max(solve(1, 0), solve(1, 1));
}