#include <bits/stdc++.h>

using namespace std;

int N, forest[500][500], cache[500][500], ans = 0;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int solve(int y, int x)
{
    int& ret = cache[y][x];
    if (ret != -1) return ret;
    ret = 0;

    for (int i = 0; i < 4; i++)
    {
        int nextY = y + dy[i], nextX = x + dx[i];
        if ((nextY < 0 || nextY >= N) ||
                (nextX < 0 || nextX >= N)) continue;
        
        if (forest[y][x] < forest[nextY][nextX])
        {
            ret = max(ret, 1 + solve(nextY, nextX));
        }
    }

    return ret;
}

void solve()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            ans = max(ans, solve(i, j));
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    memset(cache, -1, sizeof(cache));

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> forest[i][j];
        }
    }

    solve();

    cout << ans;
}