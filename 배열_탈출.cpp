#include <bits/stdc++.h>

using namespace std;

int n, A[2222][2222], cache[2222][2222];

int solve(int y, int x)
{
    if (y == n - 1 && x == n - 1) return 0;

    int& ret = cache[y][x];
    if (ret != -1) return ret;
    ret = 2100000000;

    if (y < n - 1)
    {
        int cost = (A[y][x] <= A[y + 1][x]) ? A[y + 1][x] - A[y][x] + 1 : 0;
        ret = min(ret, cost + solve(y + 1, x));
    }
    if (x < n - 1)
    {
        int cost = (A[y][x] <= A[y][x + 1]) ? A[y][x + 1] - A[y][x] + 1 : 0;
        ret = min(ret, cost + solve(y, x + 1));
    }

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }
    
    cout << solve(0, 0);
}