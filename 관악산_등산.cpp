#include <bits/stdc++.h>

using namespace std;

int N, M, cache[5001], adj[5001][5001], h[5001];

int solve(int idx)
{


    int& ret = cache[idx];
    if (ret != -1) return ret;
    ret = 1;

    for (int i = 1; i <= N; i++)
    {
        if (adj[idx][i] && h[idx] < h[i])
            ret = max(ret, 1 + solve(i));
    }

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> h[i];
    }
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = adj[v][u] = 1;
    }

    for (int i = 1; i <= N; i++)
    {
        cout << solve(i) << "\n";
    }
}