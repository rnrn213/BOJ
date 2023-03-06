#include <bits/stdc++.h>

using namespace std;

int N, p[4], adj[30][30];
int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};

double dfs(int y, int x, int n) {
    if (n == 0) return 1.0;

    double ret = 0.0;
    for (int i = 0; i < 4; i++) {
        int nextY = y + dy[i], nextX = x + dx[i];
        if (adj[nextY][nextX] == 0) {
            adj[nextY][nextX]++;
            ret += (p[i] / 100.0) * dfs(nextY, nextX, n - 1);
            adj[nextY][nextX]--;
        }
    }

    return ret;
}

int main() {
    cout << fixed;
    cout.precision(10);

    memset(adj, 0, sizeof(adj));
    adj[14][14] = 1;
    
    cin >> N;
    for (int i = 0; i < 4; i++)
        cin >> p[i];
    
    cout << dfs(14, 14, N);
}