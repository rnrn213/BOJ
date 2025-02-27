#include <bits/stdc++.h>

using namespace std;

const int INF = 10001;

int N, M, S[101], cache[10001];

int solve(int idx)
{
    if (idx == 0) return 0;

    int& ret = cache[idx];
    if (ret != -1) return ret;
    ret = INF;

    for (int i = 1; i <= M; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            if (i == j)
                continue;
            if (idx >= S[i] + S[j])
                ret = min(ret, 1 + solve(idx - (S[i] + S[j])));
        }
    }

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        cin >> S[i];
    }

    int ans = solve(N);
    if (ans >= INF) cout << -1;
    else cout << ans;
}