#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int N, M, T[501][501], cache[501][501];

int solve(int idx, int prev)
{
    if (idx > N) return 0;

    int& ret = cache[idx][prev];
    if (ret != -1) return ret;
    ret = INF;

    for (int i = 1; i <= M; i++)
    {
        if (i == prev) continue;

        ret = min(ret, T[idx][i] + solve(idx + 1, i));
    }

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> T[i][j];
        }
    }

    cout << solve(1, 0);
}