#include <bits/stdc++.h>

using namespace std;

int N, M, D[10001], cache[10001][501];

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> D[i];
    }
    for (int i = 1; i <= M; i++)
    {
        cache[0][i] = -2100000000;
    }

    for (int i = 1; i <= N; i++)
    {
        cache[i][0] = cache[i - 1][0];
        for (int j = 1; j <= M; j++)
        {
            if (i - j > 0) cache[i][0] = max(cache[i][0], cache[i - j][j]);
            cache[i][j] = D[i] + cache[i - 1][j - 1];
        }
    }

    cout << cache[N][0];
}