#include <bits/stdc++.h>

using namespace std;

int N, A[501], cache[501][501], cnt = 0;

int solve()
{
    int ret = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 1; k < i; k++)
            {
                int x = (j - k <= 0) ? j - k + N : j - k;
                if (A[j] > A[x]) cache[i][j] = max(cache[i][j], 1 + cache[i - k][x]);
            }
            if (ret < cache[i][j]) ret = cache[i][j];
        }
    }
    return ret;
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
        cache[1][i] = 1;
    }
    int AS = solve();

    

    memset(cache, 0, sizeof(cache));
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
        cache[1][i] = 1;
    }
    int BS = solve();

    if (AS > BS) cout << "YJ Win!";
    if (AS == BS) cout << "Both Win!";
    if (AS < BS) cout << "HG Win!";
}