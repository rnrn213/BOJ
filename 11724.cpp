#include <bits/stdc++.h>

using namespace std;

int N, M;

void bfs(const vector< vector<bool> >& graph, vector<bool>& isVisited, int u) {
    queue<int> q;
    q.push(u);
    isVisited[u] = true;

    while (!q.empty()) {
        int n = q.front();
        q.pop();

        for (int i = 1; i <= N; i++) {
            if (graph[n][i] && !isVisited[i]) {
                q.push(i);
                isVisited[i] = true;
            }
        }
    }
}

int main() {
    cin >> N >> M;
    vector< vector<bool> > graph(N + 1, vector<bool>(N + 1, false));
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = graph[v][u] = true;
    }

    vector<bool> isVisited(N + 1, false);
    int ConnectedComponentCnt = 0;
    for (int i = 1; i <= N; i++) {
        if (!isVisited[i]) {
            bfs(graph, isVisited, i);
            ConnectedComponentCnt++;
        }
    }

    cout << ConnectedComponentCnt;
}