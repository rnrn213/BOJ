#include <bits/stdc++.h>

using namespace std;

int N, M, friendCnt;
vector< vector<int> > adj(2000);
bool visited[2000];

bool dfs(int f) {
    if (friendCnt == 5) return true;

    bool ret = false;
    for (int i = 0; i < adj[f].size(); i++) {
        if (!visited[adj[f][i]]) {
            visited[adj[f][i]] = true;
            friendCnt++;
            ret = ret || dfs(adj[f][i]);
            visited[adj[f][i]] = false;
            friendCnt--;
        }
    }

    return ret;
}

int solve() {
    int ret = 0;
    for (int i = 0; i < N; i++) {
        visited[i] = true;
        friendCnt = 1;
        if (dfs(i)) {
            ret = 1;
            break;
        }
        visited[i] = false;
    }

    return ret;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }

    cout << solve();
}