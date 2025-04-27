#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int N, cache[101][10][2][3];

int solve(int idx, int num, int m, int cnt)
{
    if (idx == N - 1) return 1;

    int& ret = cache[idx][num][m][cnt];
    if (ret != -1) return ret;
    ret = 0;

    if (m == 0 && num != 9 && idx > 0)
        ret = (ret + solve(idx + 1, num + 1, 1, 1)) % MOD;
    if (m == 1 && num != 0 && idx > 0)
        ret = (ret + solve(idx + 1, num - 1, 0, 1)) % MOD;

    if (cnt < 2)
    {
        if (m == 0 && num > 0)
            ret = (ret + solve(idx + 1, num - 1, 0, cnt + 1)) % MOD;
        if (m == 1 && num < 9)
            ret = (ret + solve(idx + 1, num + 1, 1, cnt + 1)) % MOD;
    }

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N;

    if (N == 1) cout << 10;
    else
    {
        int ans = 0;
        for (int i = 0; i < 10; i++)
        {
            if (i > 0)
                ans = (ans + solve(0, i, 0, 0)) % MOD;
            if (i < 9)
                ans = (ans + solve(0, i, 1, 0)) % MOD;
        }
        cout << ans;
    }
}