#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int N, K, C[101], cache[101][100001];

int solve(int idx, int cf)
{
    if (idx == N) return (cf == 0) ? 0 : INF;

    int& ret = cache[idx][cf];
    if (ret != -1) return ret;
    ret = INF;

    return ret = min({ret, solve(idx + 1, cf), 1 + solve(idx + 1, cf - C[idx])});
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> C[i];
    }

    int ans = solve(0, K);
    if (ans >= INF) cout << -1;
    else cout << ans;
}