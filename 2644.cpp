#include <bits/stdc++.h>

using namespace std;

int n, m, adj[101][101], dok[101];
bool visited[101];

void bfs(int a) {
    queue<int> q;
    q.push(a);
    visited[a] = true;

    int dokValue = 1;
    while (true) {
        queue<int> nextQ;

        while (!q.empty()) {
            int t = q.front();
            q.pop();

            for (int i = 1; i <= n; i++) {
                if (adj[t][i] == 1 && !visited[i]) {
                    nextQ.push(i);
                    visited[i] = true;
                    dok[i] = dokValue;
                }
            }
        }

        if (nextQ.empty()) break;

        q = nextQ;
        dokValue++;
    }
}

int main() {
    memset(dok, -1, sizeof(dok));
    memset(adj, 0, sizeof(adj));
    memset(visited, false, sizeof(visited));

    cin >> n;

    int a, b;
    cin >> a >> b;

    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x][y] = adj[y][x] = 1;
    }

    bfs(a);

    cout << dok[b];
}