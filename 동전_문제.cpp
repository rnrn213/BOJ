#include <bits/stdc++.h>

using namespace std;

int T, cache[101];

int solve(int num)
{
    if (num == 0) return 0;

    int& ret = cache[num];
    if (ret != -1) return ret;
    ret = 100000;

    ret = min(ret, 1 + solve(num - 1));
    if (num >= 10) ret = min(ret, 1 + solve(num - 10));
    if (num >= 25) ret = min(ret, 1 + solve(num - 25));

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));
    cache[0] = 0;

    for (int i = 1; i < 100; i++)
    {
        solve(i);
    }

    cin >> T;
    while (T--)
    {
        long long c;
        cin >> c;

        int ans = 0;
        while (c)
        {
            ans += cache[c % 100];
            c /= 100;
        }
        cout << ans << "\n";
    }
}