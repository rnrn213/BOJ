#include <bits/stdc++.h>

using namespace std;

int n, m, arr[31], cache[31][33];

int solve(int r, int s)
{
    if (r == n - 1)
    {
        if (arr[r] == -1 || arr[r] == s) return 1;
        else return 0;
    }
    
    int& ret = cache[r][s];
    if (ret != -1) return ret;

    if (arr[r] == -1 || arr[r] == s) ret = solve(r + 1, s) + solve(r + 1, s + 1);
    else ret = 0;

    return ret;
}

int main()
{
    memset(arr, -1, sizeof(arr));
    memset(cache, -1, sizeof(cache));

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int r, s;
        cin >> r >> s;
        arr[r] = s;
    }

    cout << solve(0, 0);
}