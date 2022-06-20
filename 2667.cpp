#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > direction = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

int main() {
    int N;
    cin >> N;
    vector< vector<int> > map(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    vector< vector<bool> > isVisited(N, vector<bool>(N, false));
    vector<int> homeCnts;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1 && !isVisited[i][j]) {
                queue< pair<int, int> > q;
                q.push(make_pair(i, j));
                isVisited[i][j] = true;
                int homeCnt = 1;

                while (!q.empty()) {
                    pair<int, int> p = q.front();
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        if ((p.first + direction[k][0] >= 0 && p.first + direction[k][0] < N) &&
                            (p.second + direction[k][1] >= 0 && p.second + direction[k][1] < N) &&
                            (map[p.first + direction[k][0]][p.second + direction[k][1]] == 1 && !isVisited[p.first + direction[k][0]][p.second + direction[k][1]])) {
                                q.push(make_pair(p.first + direction[k][0], p.second + direction[k][1]));
                                isVisited[p.first + direction[k][0]][p.second + direction[k][1]] = true;
                                homeCnt++;
                            }
                    }
                }

                homeCnts.push_back(homeCnt);
            }
        }
    }

    sort(homeCnts.begin(), homeCnts.end());
    cout << homeCnts.size() << "\n";
    for (auto homeCnt : homeCnts) {
        cout << homeCnt << "\n";
    }
}