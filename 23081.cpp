#include <bits/stdc++.h>

using namespace std;

int N;
vector< vector<char> > board;
vector< pair<int, int> > direction = {make_pair(-1, 0), make_pair(-1, 1), make_pair(0, 1), make_pair(1, 1), make_pair(1, 0), make_pair(1, -1), make_pair(0, -1), make_pair(-1, -1)};

int countUpside(int y, int x, int k) {

}

int solve() {
    int ret = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == '.') {
                int cnt = 0;
                for (int k = 0; k < 8; k++) {
                    cnt += countUpside(i, j, k);
                }

                ret = max(ret, cnt);
            }
        }
    }

    return ret;
}

int main() {
    cin >> N;
    board = vector< vector<char> >(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    cout << solve();
}