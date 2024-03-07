#include <bits/stdc++.h>

using namespace std;

int N, home[33][33];
long long cache[33][33][3];

long long solve(int y, int x, int direction)
{
    if (y == N && x == N) return 1;

    long long& ret = cache[y][x][direction];
    if (ret != -1) return ret;
    ret = 0;

    if (direction == 0)
    {
        if (x + 1 <= N && home[y][x + 1] == 0)
        {
            ret += solve(y, x + 1, 0);
        }
        if ((y + 1 <= N && x + 1 <= N) &&
                (home[y][x + 1] == 0 && home[y + 1][x] == 0 && home[y + 1][x + 1] == 0))
        {
            ret += solve(y + 1, x + 1, 1);
        }
    }
    else if (direction == 1)
    {
        if (x + 1 <= N && home[y][x + 1] == 0)
        {
            ret += solve(y, x + 1, 0);
        }
        if ((y + 1 <= N && x + 1 <= N) &&
                (home[y][x + 1] == 0 && home[y + 1][x] == 0 && home[y + 1][x + 1] == 0))
        {
            ret += solve(y + 1, x + 1, 1);
        }
        if (y + 1 <= N && home[y + 1][x] == 0)
        {
            ret += solve(y + 1, x, 2);
        }
    }
    else
    {

        if (y + 1 <= N && home[y + 1][x] == 0)
        {
            ret += solve(y + 1, x, 2);
        }
        if ((y + 1 <= N && x + 1 <= N) &&
                (home[y][x + 1] == 0 && home[y + 1][x] == 0 && home[y + 1][x + 1] == 0))
        {
            ret += solve(y + 1, x + 1, 1);
        }
    }

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> home[i][j];
        }
    }

    cout << solve(1, 2, 0);
}