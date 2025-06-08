#include <bits/stdc++.h>

using namespace std;

int N, P[10001], cache[10001][2][2];
vector<int> adj[10001];
vector<bool> visited(10001, false);

int solve(int idx, int here, int prev)
{
    visited[idx] = true;

    int& ret = cache[idx][here][prev];
    if (ret != -1) return ret;
    ret = (here == 1) ? P[idx] : 0;

    int select = 0, minDiff = 123456;
    for (int i = 0; i < adj[idx].size(); i++)
    {
        if (visited[adj[idx][i]]) continue;

        int x = solve(adj[idx][i], 0, here);
        if (here == 0)
        {
            int y = solve(adj[idx][i], 1, here);
            if (y > x)
            {
                ret += y;
                select++;
            }
            else
            {
                ret += x;
                if (minDiff > x - y)
                    minDiff = x - y;
            }
        }
        else
            ret += x;
    }

    if (here == 0 && prev == 0 && select == 0)
    {
        ret -= minDiff;
    }

    visited[idx] = false;

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> P[i];
    }
    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = solve(1, 0, 0);
    ans = max(ans, solve(1, 1, 0));
    cout << ans;
}