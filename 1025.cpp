#include <bits/stdc++.h>

using namespace std;

int N, M;
vector< vector<int> > board(9, vector<int>(9));
vector<int> direction = {1, -1};

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string num;
        cin >> num;
        for (int j = 0; j < num.size(); j++) {
            board[i][j] = num[j] - '0';
        }
    }

    int ans = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int dy = 0; dy < N; dy++) {
                for (int dx = 0; dx < M; dx++) {
                    if (dy == 0 && dx == 0) {
                        if (static_cast<int>(pow((int)(sqrt((double)board[i][j]) + 0.5), 2) + 0.5) == board[i][j] && ans < board[i][j]) {
                                ans = board[i][j];
                        }
                        continue;
                    }
                    for (int d1 = 0; d1 < 2; d1++) {
                        for (int d2 = 0; d2 < 2; d2++) {
                            int num = 0, y = i, x = j, k = 0;
                            while ((y >= 0 && x >= 0) && (y < N && x < M)) {
                                num += board[y][x] * pow(10, k);

                                if (static_cast<int>(pow((int)(sqrt((double)num) + 0.5), 2) + 0.5) == num && ans < num) {
                                    ans = num;
                                }

                                y += dy * direction[d1];
                                x += dx * direction[d2];
                                k++;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << ans;
}