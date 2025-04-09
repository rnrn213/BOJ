#include <bits/stdc++.h>

using namespace std;

int N, v[2001], cache[2001][2001];

int solve(int l, int r)
{
    if (l == r) return N * v[l];

    int& ret = cache[l][r];
    if (ret != -1) return ret;

    int m = N - (r - l);
    return ret = max(m * v[l] + solve(l + 1, r), m * v[r] + solve(l, r - 1));
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    cout << solve(0, N - 1);
}