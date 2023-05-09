#include <bits/stdc++.h>

using namespace std;

const int INF = 2100000000;

int T, n, d, c;
vector< pair<int, int> > adj[10001];

pair<int, int> dijkstra() {
    vector<int> dist(n+1, INF);
    dist[c] = 0;

    priority_queue< pair<int, int> > pq;
    pq.push(make_pair(0, c));

    pair<int, int> ret = make_pair(0, 0);
    while (!pq.empty()) {
        int cost = -1*pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (dist[here] < cost) continue;

        ret.first++;
        if (ret.second < cost)
            ret.second = cost;

        for (int i = 0; i < adj[here].size(); i++) {
            int next = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;
            if (dist[next] > nextDist) {
                dist[next] = nextDist;
                pq.push(make_pair(-1*nextDist, next));
            }
        }
    }

    return ret;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n >> d >> c;
        for (int i = 0; i <= n; i++) {
            adj[i].clear();
        }
        for (int j = 0; j < d; j++) {
            int a, b, s;
            cin >> a >> b >> s;
            adj[b].push_back(make_pair(a, s));
        }

        pair<int, int> ans = dijkstra();
        cout << ans.first << " " << ans.second << "\n";
    }
}