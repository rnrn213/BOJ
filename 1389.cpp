#include <bits/stdc++.h>

using namespace std;

int N, M;
vector< vector<bool> > isFriend;


int getKevinBacon(int v) {
    vector<bool> isVisited(N + 1, false);
    queue<int> prevQ;

    prevQ.push(v);
    isVisited[v] = true;
    int kevinBacon = 0, depth = 1, visitedCnt = 1;
    while (visitedCnt < N) {
        queue<int> nextQ;

        while (!prevQ.empty()) {
            int n = prevQ.front();
            prevQ.pop();

            for (int i = 1; i <= N; i++) {
                if (isFriend[n][i] && !isVisited[i]) {
                    nextQ.push(i);
                    isVisited[i] = true;
                    visitedCnt++;
                }
            }
        }

        kevinBacon += nextQ.size() * depth;
        depth++;
        prevQ = nextQ;
    }

    return kevinBacon;
}

int main() {
    cin >> N >> M;
    isFriend = vector< vector<bool> >(N + 1, vector<bool>(N + 1, false));
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        isFriend[u][v] = isFriend[v][u] = true;
    }

    int minKevinBacon = 100000000, ans = -1;
    for (int i = 1; i <= N; i++) {
        int ithKevinBacon = getKevinBacon(i);
        if (ithKevinBacon < minKevinBacon) {
            minKevinBacon = ithKevinBacon;
            ans = i;
        }
    }

    cout << ans;
}