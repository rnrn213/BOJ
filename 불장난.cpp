#include <bits/stdc++.h>

using namespace std;

const int MOD = 10007;

int n, cache[101][101][101];
int dy[] = {0, 1};

int solve(int idx, int k, int m)
{
    if (idx == n - 1) return 1;

    int& ret = cache[idx][k][m];
    if (ret != -1) return ret;
    ret = 0;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (k + dy[i] == m + dy[j]) continue;

            ret = (ret + solve(idx + 1, k + dy[i], m + dy[j])) % MOD;
        }
    }

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> n;

    cout << (solve(1, 0, 1) + solve(1, 1, 0)) % MOD;
}