#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > direction = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int M, N, K;
        cin >> M >> N >> K;
        vector< vector<bool> > field(N, vector<bool>(M, false));
        for (int j = 0; j < K; j++) {
            int X, Y;
            cin >> X >> Y;
            field[Y][X] = true;
        }

        int cnt = 0;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (field[y][x] == true) {
                    queue< pair<int, int> > q;
                    q.push(make_pair(y, x));
                    field[y][x] = false;
                    while (!q.empty()) {
                        int tempY = q.front().first, tempX = q.front().second;
                        q.pop();

                        for (int j = 0; j < 4; j++) {
                            if ((tempY + direction[j][0] >= 0 && tempY + direction[j][0] < N)
                                && (tempX + direction[j][1] >= 0 && tempX + direction[j][1] < M)
                                && field[tempY + direction[j][0]][tempX + direction[j][1]] == true) {
                                q.push(make_pair(tempY + direction[j][0], tempX + direction[j][1]));
                                field[tempY + direction[j][0]][tempX + direction[j][1]] = false;
                            }
                        }
                    }
                    cnt++;
                }
            }
        }

        cout << cnt << "\n";
    }
}