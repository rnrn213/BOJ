#include <bits/stdc++.h>

using namespace std;

const int MONEY_MAX = 123456789;

int N, M, k, A[10001], visited[10001];
vector< vector<int> > adj(10001);

int dfs(int f) {
    int& ret = visited[f];
    ret = A[f];

    for (int i = 0; i < adj[f].size(); i++) {
        if (visited[adj[f][i]] == MONEY_MAX) {
            ret = min(ret, dfs(adj[f][i]));
        }
    }

    return ret;
}

int getMinCost() {
    int minCost = 0;
    for (int i = 1; i <= N; i++) {
        if (visited[i] == MONEY_MAX)
            minCost += dfs(i);
    }
    return minCost;
}

int main() {
    cin.tie(NULL);
	ios::sync_with_stdio(false);

    cin >> N >> M >> k;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        int v, w;
        cin >> v >> w;
        adj[v].push_back(w); adj[w].push_back(v);
    }

    for (int i = 0; i < 10001; i++) {
        visited[i] = MONEY_MAX;
    }

    int minCost = getMinCost();
    if (minCost > k) cout << "Oh no";
    else cout << minCost;
}