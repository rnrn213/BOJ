#include <bits/stdc++.h>

using namespace std;

const int INF = 2100000000;

int N, K;
vector< pair<int, int> > adj[100001];

int dijkstra(int start, int end) {
    vector<int> dist(100001, INF);
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
    cin >> N >> K;
    for (int i = 0; i <= 100000; i++) {
        if (i > 0)
            adj[i].push_back(make_pair(i-1, 1));
        if (i < 100000)
            adj[i].push_back(make_pair(i+1, 1));
        if (i*2 <= 100000)
            adj[i].push_back(make_pair(i*2, 0));
    }

    cout << dijkstra(N, K);
}