#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > direction = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int main() {
    int N;
    cin >> N;
    vector< vector<char> > picture(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> picture[i][j];
        }
    }

    vector< vector<bool> > isVisited(N, vector<bool>(N, false));
    int RorGzone = 0, RGzone = 0, Bzone = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!isVisited[i][j]) {
                queue< pair<int, int> > q;
                q.push(make_pair(i, j));
                isVisited[i][j] = true;

                while (!q.empty()) {
                    pair<int, int> p = q.front();
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        if ((p.first + direction[k][0] >= 0 && p.first + direction[k][0] < N) &&
                            (p.second + direction[k][1] >= 0 && p.second + direction[k][1] < N) &&
                            (picture[p.first + direction[k][0]][p.second + direction[k][1]] == picture[p.first][p.second] && !isVisited[p.first + direction[k][0]][p.second + direction[k][1]])) {
                            
                            q.push(make_pair(p.first + direction[k][0], p.second + direction[k][1]));
                            isVisited[p.first + direction[k][0]][p.second + direction[k][1]] = true;
                        }
                    }
                }

                if (picture[i][j] == 'R' || picture[i][j] == 'G')
                    RorGzone++;
                else
                    Bzone++;
            }
        }
    }

    isVisited = vector< vector<bool> >(N, vector<bool>(N, false));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!isVisited[i][j] && (picture[i][j] == 'R' || picture[i][j] == 'G')) {

                queue< pair<int, int> > q;
                q.push(make_pair(i, j));
                isVisited[i][j] = true;

                while (!q.empty()) {
                    pair<int, int> p = q.front();
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        if ((p.first + direction[k][0] >= 0 && p.first + direction[k][0] < N) &&
                            (p.second + direction[k][1] >= 0 && p.second + direction[k][1] < N) &&
                            (picture[p.first + direction[k][0]][p.second + direction[k][1]] == 'R' || picture[p.first + direction[k][0]][p.second + direction[k][1]] == 'G') && 
                            (!isVisited[p.first + direction[k][0]][p.second + direction[k][1]])) {
                            
                            q.push(make_pair(p.first + direction[k][0], p.second + direction[k][1]));
                            isVisited[p.first + direction[k][0]][p.second + direction[k][1]] = true;
                        }
                    }
                }

                RGzone++;
            }
        }
    }

    cout << RorGzone + Bzone << " " << RGzone + Bzone;
}