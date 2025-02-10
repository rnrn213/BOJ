#include <bits/stdc++.h>

using namespace std;

int T, n, k, cache[101][101][2];

int solve(int len, int cnt, int r)
{
    if (len == 1)
    {
        if (cnt == 0) return 1;
        else return 0;
    }

    int& ret = cache[len][cnt][r];
    if (ret != -1) return ret;
    ret = solve(len - 1, cnt, 0);

    if (r == 0)
        ret += solve(len - 1, cnt, 1);
    if (r == 1 && cnt > 0)
        ret += solve(len - 1, cnt - 1, 1);

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        cout << solve(n, k, 0) + solve(n, k, 1) << "\n";
    }
}