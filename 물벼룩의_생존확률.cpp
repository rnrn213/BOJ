#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int k, n;
ll cache[64][150];

ll solve(int t, int d)
{
    if (t == n)
    {
        if (d == 0) return 0;
        else return 1;
    }
    if (d == 0) return 0;

    ll& ret = cache[t][d];
    if (ret != -1) return ret;
    ret = 0;

    return ret += solve(t + 1, d - 1) + solve(t + 1, d + 1);
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> k >> n;

    cout << solve(0, k);
}