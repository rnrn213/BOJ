#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<string> adj(1000);
bool visited[1000][1000][2];
int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1};

bool isValid(int y, int x) {
    if ((y >= 0 && y < N) && (x >= 0 && x < M))
        return true;
    return false;
}

int bfs() {
    queue< tuple<int, int, int> > q;
    q.push(make_tuple(0, 0, 1));

    int pathLength = 1;
    while (!q.empty()) {
        queue< tuple<int, int, int> > nextQ;

        while (!q.empty()) {
            tuple<int, int, int> t = q.front();
            int canSmashWall = get<2>(t);
            q.pop();

            if (get<0>(t) == N - 1 && get<1>(t) == M - 1)
                return pathLength;

            for (int i = 0; i < 4; i++) {
                int nextY = get<0>(t) + dy[i], nextX = get<1>(t) + dx[i];
                if (isValid(nextY, nextX) && !visited[nextY][nextX][canSmashWall]) {
                    visited[nextY][nextX][canSmashWall] = true;
                    
                    if (adj[nextY][nextX] == '0')
                        nextQ.push(make_tuple(nextY, nextX, canSmashWall));
                    else if (canSmashWall) 
                        nextQ.push(make_tuple(nextY, nextX, !canSmashWall));
                }
            }
        }

        q = nextQ;
        pathLength++;
    }

    return -1;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    memset(visited, false, sizeof(visited));

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> adj[i];
    }

    cout << bfs();
}