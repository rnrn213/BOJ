#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> adj[100001];
vector<bool> visited(100001, false);

const int UNWATCHED = 0;
const int WATCHED = 1;
const int INSTALLED = 2;

int installed = 0;

int dfs(int here) {
    visited[here] = true;
    int children[3] = {0, 0, 0};
    for (int i = 0; i < adj[here].size(); i++) {
        int there = adj[here][i];
        if (!visited[there])
            ++children[dfs(there)];
    }

    if (children[UNWATCHED] || children[WATCHED]) {
        ++installed;
        return INSTALLED;
    }
    if (children[INSTALLED]) {
        return WATCHED;
    }
    return UNWATCHED;
}

void solve() {
    if (dfs(1) == UNWATCHED)
        ++installed;
}

int main() {
    cin >> N;
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    solve();

    cout << installed;
}