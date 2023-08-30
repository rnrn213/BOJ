#include <bits/stdc++.h>

using namespace std;

const int INF = 1000000000;

int N, E;
vector< pair<int, int> > adj[801];

vector<int> dijkstra(int src) {
    vector<int> dist(N + 1, INF);
    dist[src] = 0;

    priority_queue< pair<int, int> > pq;
    pq.push(make_pair(0, src));
    while (!pq.empty()) {
        int cost = -1 * pq.top().first,
              here = pq.top().second;
        pq.pop();

        if (dist[here] < cost) continue;

        for (int i = 0; i < adj[here].size(); i++) {
            int next = adj[here][i].first,
                  nextDist = cost + adj[here][i].second;
            if (dist[next] > nextDist) {
                dist[next] = nextDist;
                pq.push(make_pair(-1 * nextDist, next));
            }
        }
    }

    return dist;
}


int main() {
    cin >> N >> E;
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }

    int v1, v2;
    cin >> v1 >> v2;

    vector<int> v1Dist = dijkstra(v1),
                  v2Dist = dijkstra(v2);

    if ((v1Dist[1] == INF || v1Dist[N] == INF) ||
          (v2Dist[1] == INF || v2Dist[N] == INF) ||
          (v1Dist[v2] == INF)) {
        cout << -1;
    }
    else {
        int ans = min(v1Dist[1] + v1Dist[v2] + v2Dist[N],
                        v2Dist[1] + v2Dist[v1] + v1Dist[N]);
        cout << ans;
    }
}