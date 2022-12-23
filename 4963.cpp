#include <bits/stdc++.h>

using namespace std;

int w, h, m[50][50];
bool visited[50][50];

vector< vector<int> > direction = { {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1} };

bool isValidLocation(int i, int j) {
    return (i >= 0 && i < h) && (j >= 0 && j < w);
}

void dfs(int i, int j) {
    visited[i][j] = true;

    for (int k = 0; k < direction.size(); k++) {
        int nextI = i + direction[k][0];
        int nextJ = j + direction[k][1];
        if (isValidLocation(nextI, nextJ) && m[nextI][nextJ] == 1 && visited[nextI][nextJ] == false)
            dfs(nextI, nextJ);
    }

    return;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    while (true) {
        memset(visited, false, sizeof(visited));

        cin >> w >> h;
        if (w == 0 && h == 0) break;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> m[i][j];
            }
        }

        int cntIsland = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (!visited[i][j] && m[i][j] == 1) {
                    dfs(i, j);
                    cntIsland++;
                }
            }
        }

        cout << cntIsland << "\n";
    }
}