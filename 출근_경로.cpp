#include <bits/stdc++.h>

using namespace std;

const int MOD = 100000;

int w, h, arr[101][101], cache[101][101][2][2];

int solve(int x, int y, int d, int prev)
{
    if (x == w && y == h) return 1;

    int& ret = cache[x][y][d][prev];
    if (ret != -1) return ret;
    ret = 0;

    if (prev == 0)
    {
        if (x < w)
        {
            if (d == 0)
                ret = (solve(x + 1, y, 0, 0)) % MOD;
            else
                ret = (solve(x + 1, y, 0, 1)) % MOD;
        }
        if (y < h)
        {
            if (d == 1)
                ret = (ret + solve(x, y + 1, 1, 0)) % MOD;
            else
                ret = (ret + solve(x, y + 1, 1, 1)) % MOD;
        }
    }
    else if (d == 0 && x < w)
        ret = (solve(x + 1, y, 0, 0)) % MOD;
    else if (d == 1 && y < h)
        ret = (solve(x, y + 1, 1, 0)) % MOD;


    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> w >> h;

    cout << (solve(2, 1, 0, 0) + solve(1, 2, 1, 0)) % MOD;
}