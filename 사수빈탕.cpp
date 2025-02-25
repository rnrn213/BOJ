#include <bits/stdc++.h>

using namespace std;

int N, M, arr[301][301], cache[301][301];

int solve(int x, int y)
{
    if (x == 300 && y == 300)
    {
        return (arr[x][y] - (x + y) >= 0) ? arr[x][y] - (x + y) : 0;
    }

    int& ret = cache[x][y];
    if (ret != -1) return ret;
    ret = 0;

    int c = (arr[x][y] - (x + y) >= 0) ? arr[x][y] - (x + y) : 0;

    if (x < 300)
        ret = max(ret, c + solve(x + 1, y));
    if (y < 300)
        ret = max(ret, c + solve(x, y + 1));

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[x][y] = M;
    }

    cout << solve(0, 0);
}