#include <bits/stdc++.h>

using namespace std;

int N, M, K, X[101], Y[101], cache[101][301][301];

int solve(int idx, int c, int p)
{
    if (idx == N) return 0;

    int& ret = cache[idx][c][p];
    if (ret != -1) return ret;
    ret = solve(idx + 1, c, p);

    if (c - X[idx] >= 0 && p - Y[idx] >= 0)
        ret = max(ret, 1 + solve(idx + 1, c - X[idx], p - Y[idx]));

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> X[i] >> Y[i];
    }

    cout << solve(0, M, K);
}