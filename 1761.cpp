#include <bits/stdc++.h>

using namespace std;

int N, M;
vector< pair<int,int> > adj[40001], parent(100001);
vector<bool> visited(40001, false);
vector<int> level(40001);

void makeTree(int node, int lv) {
    for (int i = 0; i < adj[node].size(); i++) {
        int next = adj[node][i].first, 
            dist = adj[node][i].second;
        if (!visited[next]) {
            visited[next] = true;
            parent[next] = make_pair(node, dist);
            level[next] = lv + 1;
            makeTree(next, lv+1);
        }
    }
}

int lca(int u, int v) {
    if (level[u] < level[v]) swap(u, v);

    int d = 0;
    while (level[u] != level[v]) {
        d += parent[u].second;
        u = parent[u].first;
    }

    while (u != v) {
        d += parent[u].second + parent[v].second;
        u = parent[u].first;
        v = parent[v].first;
    }

    return d;
}

int main() {
    cin >> N;
    for (int i = 0; i < N-1; i++) {
        int u, v, dist;
        cin >> u >> v >> dist;
        adj[u].push_back(make_pair(v, dist));
        adj[v].push_back(make_pair(u, dist));
    }

    visited[1] = true;
    level[1] = 1;
    makeTree(1, 1);

    cin >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << "\n";
    }
}