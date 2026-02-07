#include <bits/stdc++.h>

using namespace std;

const int MOD = 987654321;

typedef long long ll;

int N;
ll cache[10001];

ll solve(int x)
{
    if (x == 1) return 0;
    if (x == 0 || x == 2) return 1;

    ll& ret = cache[x];
    if (ret != -1) return ret;
    ret = 0;

    for (int i = 2; i <= x; i++)
    {
        ret = (ret + solve(x - i) * solve(i - 2)) % MOD;
    }

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N;

    cout << solve(N);
}