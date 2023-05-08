#include <bits/stdc++.h>

using namespace std;

const int INF = 2100000000;

int N, M;
vector< pair<int, int> > adj[1001];

int dijkstra(int start, int end) {
    vector<int> dist(N+1, INF);
    dist[start] = 0;

    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int cost = pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (dist[here] < cost) continue;

        for (int i = 0; i < adj[here].size(); i++) {
            int next = adj[here][i].first;
            int d = cost + adj[here][i].second;
            if (d < dist[next]) {
                dist[next] = d;
                pq.push(make_pair(d, next));
            }
        }
    }

    return dist[end];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    int start, end, cost;
    for (int i = 0; i < M; i++) {
        cin >> start >> end >> cost;

        adj[start].push_back(make_pair(end, cost));
    }

    cin >> start >> end;
    cout << dijkstra(start, end);
}