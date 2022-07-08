#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector< vector<int> > graph(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    queue<int> q;
    vector<bool> isVisited(N + 1, false);
    q.push(1);
    isVisited[1] = true;
    vector<int> p(N+1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        int childSize = graph[u].size();
        for (int i = 0; i < childSize; i++) {
            if (!isVisited[graph[u][i]]) {
                p[graph[u][i]] = u;
                q.push(graph[u][i]);
                isVisited[graph[u][i]] = true;
            }
        }
    }

    for (int i = 2; i <= N; i++) {
        cout << p[i] << "\n";
    }
}