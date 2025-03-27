#include <bits/stdc++.h>

using namespace std;

int N, cache[31][2][2][2];

int solve(int idx, int a, int b, int c)
{
    if (idx == N) return (a == 0 && b == 0 && c == 0) ? 1 : 0;

    int& ret = cache[idx][a][b][c];
    if (ret != -1) return ret;
    ret = 0;

    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
                ret += solve(idx + 1, 1, 0, 0) + solve(idx + 1, 0, 0, 1) + solve(idx + 1, 1, 1, 1);
            else
                ret += solve(idx + 1, 0, 0, 0) + solve(idx + 1, 1, 1, 0);
        }
        else
        {
            if (c == 0)
                ret += solve(idx + 1, 1, 0, 1);
            else
                ret += solve(idx + 1, 1, 0, 0);
        }
    }
    else
    {
        if (b == 0)
        {
            if (c == 0)
                ret += solve(idx + 1, 0, 0, 0) + solve(idx + 1, 0, 1, 1);
            else
                ret += solve(idx + 1, 0, 1, 0);
        }
        else
        {
            if (c == 0)
                ret += solve(idx + 1, 0, 0, 1);
            else
                ret += solve(idx + 1, 0, 0, 0);
        }
    }

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N;

    cout << solve(0, 0, 0, 0);
}