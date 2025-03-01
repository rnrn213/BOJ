#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int N;
long long cache[1000005][3];

int main()
{
    cin >> N;

    cache[0][0] = 1;
    cache[1][0] = 2;
    cache[1][1] = 1;
    cache[1][2] = 1;

    for (int i = 2; i <= N; i++)
    {
        cache[i][0] = (2 * cache[i - 1][0] + cache[i - 1][1] + cache[i - 1][2] + cache[i - 2][0]) % MOD;
        cache[i][1] = (cache[i - 1][0] + cache[i - 1][2]) % MOD;
        cache[i][2] = (cache[i - 1][0] + cache[i - 1][1]) % MOD;
    }

    cout << cache[N][0];
}