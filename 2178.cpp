#include <bits/stdc++.h>

using namespace std;

int N, M;
vector< vector<int> > maze;

vector< vector<int> > direction = { {-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main() {
    cin >> N >> M;
    maze = vector< vector<int> >(N + 1, vector<int>(M + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%1d", &maze[i][j]);
        }
    }

    queue< pair<int, int> > prevQ;
    vector< vector<bool> > isVisited(N + 1, vector<bool>(M + 1, false));
    prevQ.push(make_pair(1, 1));
    isVisited[1][1] = true;
    int depth = 2, ans;
    while (!prevQ.empty()) {
        queue< pair<int, int> > nextQ;
        while (!prevQ.empty()) {
            pair<int, int> p = prevQ.front();
            prevQ.pop();

            for (int i = 0; i < 4; i++) {
                if ((p.first + direction[i][0] >= 1 && p.first + direction[i][0] <= N) && 
                    (p.second + direction[i][1] >= 1 && p.second + direction[i][1] <= M) &&
                    (maze[p.first + direction[i][0]][p.second + direction[i][1]] == 1 && !isVisited[p.first + direction[i][0]][p.second + direction[i][1]])) {
                    nextQ.push(make_pair(p.first + direction[i][0], p.second + direction[i][1]));
                    isVisited[p.first + direction[i][0]][p.second + direction[i][1]] = true;

                    if (p.first + direction[i][0] == N && p.second + direction[i][1] == M)
                        ans = depth;
                }
            }
        }

        prevQ = nextQ;
        depth++;
    }

    cout << ans;
}