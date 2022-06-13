#include <bits/stdc++.h>

using namespace std;

int N, M, V;

void dfs(const vector< vector<bool> >& graph, vector<bool>& isVisited, int V) {
    isVisited[V] = true;
    cout << V << " ";

    for (int i = 1; i <= N; i++) {
        if (graph[V][i] && !isVisited[i]) {
            dfs(graph, isVisited, i);
        }
    }
}

void bfs(const vector< vector<bool> >& graph, vector<bool>& isVisited, int V) {
    queue<int> q;
    q.push(V);
    isVisited[V] = true;
    cout << V << " ";

    while (!q.empty()) {
        int n = q.front();
        q.pop();

        for (int i = 1; i <= N; i++) {
            if (graph[n][i] && !isVisited[i]) {
                q.push(i);
                isVisited[i] = true;
                cout << i << " ";
            }
        }
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> N >> M >> V;
    vector< vector<bool> > graph(N + 1, vector<bool>(N + 1, false));
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        graph[a][b] = graph[b][a] = true;
    }

    vector<bool> isVisited = vector<bool>(N + 1, false);
    dfs(graph, isVisited, V);
    cout << "\n";

    isVisited = vector<bool>(N + 1, false);
    bfs(graph, isVisited, V);
}