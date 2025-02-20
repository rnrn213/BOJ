#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T, N;
ll cache[1 << 21];

ll solve(int idx, int state)
{
    if (idx == N) return 1;

    ll& ret = cache[state];
    if (ret != -1) return ret;
    ret = 0;

    for (int i = 0; i < N; i++)
    {
        if (idx == i || ((1 << i) & state)) continue;
        ret += solve(idx + 1, state | (1 << i));
    }

    return ret;
}

int main()
{
    cin >> T;
    while (T--)
    {
        memset(cache, -1, sizeof(cache));

        cin >> N;

        cout << solve(0, 0) << "\n";        
    }
}