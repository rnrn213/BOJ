#include <bits/stdc++.h>

using namespace std;

int n, ij[2], dp[10001][3];
string S, T;

int solve(int idx, int c, int sidx)
{
    if (idx == n)
    {
        if (c == 2) return 1;
        else return 0;
    }
    if (sidx == ij[0] || sidx == ij[1]) return solve(idx, c, sidx + 1);

    int& ret = dp[idx][c];
    if (ret != -1) return ret;
    ret = 0;

    if (S[sidx] == T[idx])
    {
        ret = max(ret, solve(idx + 1, c, sidx + 1));
    }
    if (c < 2 && S[ij[c]] == T[idx])
    {
        ret = max(ret, solve(idx + 1, c + 1, sidx));
    }

    return ret;
}

int main()
{
    memset(dp, -1, sizeof(dp));

    cin >> n >> S >> T >> ij[0] >> ij[1];

    if (solve(0, 0, 0)) cout << "YES";
    else cout << "NO";
}