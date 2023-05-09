#include <bits/stdc++.h>

using namespace std;

const int INF = 2100000000;

int N, M;
string adj[100];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool isValid(int y, int x) {
    if ((y < 0 || y >= N) || (x < 0 || x >= M)) return false;
    return true;
}

int dijkstra() {
    vector<int> dist(N*M, INF);
    dist[0] = 0;

    priority_queue< pair<int, int> > pq;
    pq.push(make_pair(0, 0));

    while (!pq.empty()) {
        int cost = -1*pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (dist[here] < cost) continue;

        int y = here / M, x = here % M;
        for (int i = 0; i < 4; i++) {
            int nextY = y + dy[i], nextX = x + dx[i];
            if (!isValid(nextY, nextX)) continue;

            int next = nextY * M + nextX;
            int nextDist = cost + adj[nextY][nextX] - '0';
            if (dist[next] > nextDist) {
                dist[next] = nextDist;
                pq.push(make_pair(-1*nextDist, next));
            }
        }
    }

    return dist[(N-1)*M + M-1];
}

int main() {
    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        cin >> adj[i];
    }

    cout << dijkstra();
}