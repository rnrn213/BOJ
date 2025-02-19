#include <bits/stdc++.h>

using namespace std;

int M, N, ground[1001][1001], cache[1001][1001];

int solve(int y, int x)
{
    if (ground[y][x] != 0) return 0;
    if (y == M - 1 || x == N - 1) return 1;

    int& ret = cache[y][x];
    if (ret != -1) return ret;
    ret = 1;

    int L = solve(y + 1, x + 1);
    for (int i = 1; i <= L; i++)
    {
        if (ground[y + i][x] != 0 || ground[y][x + i] != 0)
        {
           break; 
        }
        ret++;
    }

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> M >> N;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> ground[i][j];
        }
    }

    int ans = 0;
    for (int y = M - 1; y >= 0; y--)
    {
        for (int x = N - 1; x >= 0; x--)
        {
            ans = max(ans, solve(y, x));
        }
    }

    cout << ans;

}