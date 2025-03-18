#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int N, M, cache[100001][8];
vector<int> adj[100001];

int solve(int idx, int len)
{
    if (len == 7) return 1;

    int& ret = cache[idx][len];
    if (ret != -1) return ret;
    ret = 0;

    for (int i = 0; i < adj[idx].size(); i++)
    {
        ret = (ret + solve(adj[idx][i], len + 1)) % MOD;
    }

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));
    
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        ans = (ans + solve(i, 0)) % MOD;
    }

    cout << ans;
}