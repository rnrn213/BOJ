#include <bits/stdc++.h>
#include <memory>

using namespace std;

int d, m;
long long cache[4001][4001];

long long solve(int idx, int h)
{
    if (idx == d) return (h == 0) ? 1 : 0;
    if (h == 0 && (idx > 0 && idx < d)) return 0;

    long long& ret = cache[idx][h];
    if (ret != -1) return ret;
    ret = 0;

    ret = (ret + solve(idx + 1, h + 1)) % m;
    if (h > 0) ret = (ret + solve(idx + 1, h - 1)) % m;

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> d >> m;

    cout << solve(0, 0);
}
