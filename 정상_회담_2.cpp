#include <bits/stdc++.h>

using namespace std;

const int MOD = 987654321;

typedef long long ll;

int N, s[10001];
ll cache[10001];

ll solve(int num)
{
    if (num == 2 || num == 0) return 1;

    ll& ret = cache[num];
    if (ret != -1) return ret;
    ret = (2 * solve(num - 2)) % MOD;

    for (int i = 3; i < num - 1; i += 2)
    {
        ret = (ret + solve(i - 1) * solve(num - i - 1)) % MOD;
    }

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N;

    cout << solve(N);
}