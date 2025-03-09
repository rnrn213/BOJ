#include <bits/stdc++.h>

using namespace std;

int N, cache[1501][1501][3];
string s, BLD = "BLD";

int solve(int l, int r, int m)
{
    if (l > r) return 0;

    int& ret = cache[l][r][m];
    if (ret != -1) return ret;
    ret = 0;

    if (s[l] == BLD[m])
        ret = max(ret, 1 + solve(l + 1, r, (m + 1) % 3));
    if (s[r] == BLD[m])
        ret = max(ret, 1 + solve(l, r - 1, (m + 1) % 3));

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N >> s;

    cout << solve(0, 3 * N - 1, 0);
}