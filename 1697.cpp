#include <bits/stdc++.h>

using namespace std;

int N, K;
vector< vector<int> > graph(100001);

void initGraph() {
    graph[0] = vector<int>(1, 1);
    for (int i = 1; i <= 99999; i++) {
        graph[i] = {i - 1, i + 1};
        if (i <= 50000)
            graph[i].push_back(i * 2);
    }
    graph[100000] = vector<int>(1, 99999);
}

int bfs() {
    vector<bool> isVisited(100001, false);

    queue<int> prevQ;
    prevQ.push(N);
    isVisited[N] = true;
    if (N == K)
        return 0;

    int t = 1;
    while (!prevQ.empty()) {
        queue<int> nextQ;

        while (!prevQ.empty()) {
            int u = prevQ.front();
            prevQ.pop();

            for (int i = 0; i < graph[u].size(); i++) {
                if (!isVisited[graph[u][i]]) {
                    if (graph[u][i] == K)
                        return t;
                    
                    nextQ.push(graph[u][i]);
                    isVisited[graph[u][i]] = true;
                }
            }
        }

        prevQ = nextQ;
        t++;
    }

    return -1;
}

int main() {
    initGraph();

    cin >> N >> K;

    cout << bfs();
}