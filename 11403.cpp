#include <bits/stdc++.h>

using namespace std;

int N;

vector<int> dfs(const vector< vector<int> >& graph, int v) {
    vector<int> path(N, 0);
    vector<bool> isVisited(N, false);

    stack<int> s;
    s.push(v);

    while (!s.empty()) {
        int u = s.top();
        s.pop();

        for (int i = 0; i < N; i++) {
            if (graph[u][i] == 1 && !isVisited[i]) {
                s.push(i);
                isVisited[i] = true;
                path[i] = 1;
            }
        }
    }

    return path;
}

int main() {
    cin >> N;
    vector< vector<int> > graph(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }

    vector< vector<int> > path(N);
    for (int i = 0; i < N; i++) {
        path[i] = dfs(graph, i);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << path[i][j] << " ";
        }
        cout << "\n";
    }
}