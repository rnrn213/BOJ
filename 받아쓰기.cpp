#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> cache;
string A, B;

int solve(int i, int j)
{
    if (i == n) return m - j;
    if (j == m) return n - i;

    int& ret = cache[i][j];
    if (ret != -1) return ret;

    if (A[i] == B[j] || (A[i] == 'i' && (B[j] == 'j' || B[j] == 'l')) || (A[i] == 'v' && B[j] == 'w'))
        ret = solve(i + 1, j + 1);
    else if (A[i] != B[j])
    {
        ret = 1 + solve(i + 1, j);
        ret = min({ret, 1 + solve(i + 1, j + 1), 1 + solve(i, j + 1)});
    }

    return ret;
}

int main()
{
    cin >> n >> m >> A >> B;
    cache = vector<vector<int>>(n, vector<int>(m, -1));

    cout << solve(0, 0);
}