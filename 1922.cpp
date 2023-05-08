#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> ds(1001), dsRank(1001, 1);
vector< vector< pair<int, int> > > adj(1001);

int find(int n) {
    if (ds[n] == n) return n;

    return ds[n] = find(ds[n]);
}

void merge(int n, int m) {
    n = find(n); m = find(m);

    if (n == m) return;
    if (dsRank[n] > dsRank[m]) {
        int temp = n;
        n = m;
        m = temp;
    }

    ds[n] = m;
    if (dsRank[n] == dsRank[m]) dsRank[m]++;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;

        adj[A].push_back(make_pair(B, C));
        adj[B].push_back(make_pair(A, C));
    }

    for (int i = 1; i <= N; i++) {
        ds[i] = i;
    }

    vector< pair<int, pair<int, int>> > edges;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            edges.push_back(make_pair(adj[i][j].second, make_pair(i, adj[i][j].first)));
        }
    }

    sort(edges.begin(), edges.end());

    int ans = 0;
    for (int i = 0; i < edges.size(); i++) {
        int cost = edges[i].first;
        int v1 = edges[i].second.first, v2 = edges[i].second.second;

        if (find(v1) == find(v2)) continue;

        merge(v1, v2);

        ans += cost;
    }

    cout << ans;
}