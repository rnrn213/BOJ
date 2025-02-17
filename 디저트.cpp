#include <bits/stdc++.h>

using namespace std;

int N, M, d[100001][11], cache[100001][11];

int solve(int idx, int prev)
{
    if (idx == N) return 0;

    int& ret = cache[idx][prev];
    if (ret != -1) return ret;
    ret = 0;

    for (int j = 1; j <= M; j++)
    {
        if (j == prev)
            ret = max(ret, d[idx][j] / 2 + solve(idx + 1, j));
        else
            ret = max(ret, d[idx][j] + solve(idx + 1, j));
    }

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N >> M;
    for (int j = 1; j <= M; j++)
    {
        for (int i = 0; i < N; i++)
        {
            cin >> d[i][j];
        }
    }

    cout << solve(0, 0);
}