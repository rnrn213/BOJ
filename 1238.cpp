#include <bits/stdc++.h>

using namespace std;

const int INF = 2100000000;

int N, M, X;
vector< pair<int, int> > adj[1001];

int dijkstra(int start, int end) {
    vector<int> dist(N+1, INF);
    dist[start] = 0;

    priority_queue< pair<int, int> > pq;
    pq.push(make_pair(0, start));

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

    return dist[end];
}

int main() {
    cin >> N >> M >> X;
    for (int i = 0; i < M; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        adj[u].push_back(make_pair(v, t));
    }

    int maxT = -1;
    for (int i = 1; i <= N; i++) {
        int t = dijkstra(i, X) + dijkstra(X, i);
        if (t > maxT)
            maxT = t;
    }

    cout << maxT;
}