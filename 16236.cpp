#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > direction = { {1, 0}, {0, -1}, {0, 1}, {-1, 0} };

int main() {
    int N;
    cin >> N;
    vector< vector<int> > space(N, vector<int>(N));
    pair<int, int> babySharkInitialPosition;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> space[i][j];

            if (space[i][j] == 9)
                babySharkInitialPosition = make_pair(i, j);
        }
    }

    int babySharkSize = 2, eatenFishCnt = 0, totalTime = 0;
    vector< vector<bool> > isVisited(N, vector<bool>(N, false));
    queue< pair<int, int> > q;
    q.push(babySharkInitialPosition);
    isVisited[babySharkInitialPosition.first][babySharkInitialPosition.second] = true;
    while (!q.empty()) {
        queue< pair<int, int> > nextQ;

        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                if ((p.first + direction[i][0] >= 0 && p.first + direction[i][0] < N) &&
                    (p.second + direction[i][1] >= 0 && p.second + direction[i][1] < N) &&
                    !isVisited[p.first + direction[i][0]][p.second + direction[i][1]]) {
                    
                    if (space[p.first + direction[i][0]][p.second + direction[i][1]] < babySharkSize) {
                        eatenFishCnt++;
                        space[p.first + direction[i][0]][p.second + direction[i][1]] = 0;
                        break;
                    }
                    else if (space[p.first + direction[i][0]][p.second + direction[i][1]] == babySharkSize) {
                        nextQ.push(make_pair(p.first + direction[i][0], p.second + direction[i][1]));
                        isVisited[p.first + direction[i][0]][p.second + direction[i][1]] = true;
                    }
                }
            }

            if (eatenFishCnt == babySharkSize) {
                babySharkSize++;
                eatenFishCnt = 0;
                while (!q.empty()) {
                    q.pop();
                }
            }
        }
    }
}