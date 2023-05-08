#include <bits/stdc++.h>

using namespace std;

const int INF = 2100000000;

int V, E, K;
vector< pair<int, int> > adj[20001];

vector<int> dijkstra(int src) {
    vector<int> dist(V+1, INF);
    dist[src] = 0;

    priority_queue< pair<int, int> > pq;
    pq.push(make_pair(0, src));

    while (!pq.empty()) {
        int cost = -1*pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (dist[here] < cost) continue;

        for (int i = 0; i < adj[here].size(); i++) {
            int next = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;
            if (dist[next] > nextDist) {
                dist[next] = nextDist;
                pq.push(make_pair(-1*nextDist, next));
            }
        }
    }

    return dist;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> V >> E >> K;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
    }

    vector<int> dist = dijkstra(K);

    for (int i = 1; i < dist.size(); i++) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
}