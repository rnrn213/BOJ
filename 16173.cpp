#include <bits/stdc++.h>

using namespace std;

int jump(const vector< vector<int> >& gameBoard, int x, int y) {
    if (x >= gameBoard.size() || y >= gameBoard.size() || gameBoard[y][x] == 0) return 1000000;
    if (gameBoard[y][x] == -1) return -1;

    return min(jump(gameBoard, x + gameBoard[y][x], y), jump(gameBoard, x, y + gameBoard[y][x]));
}

int main() {
    int N;
    cin >> N;
    vector< vector<int> > gameBoard(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> gameBoard[i][j];
        }
    }
    if (jump(gameBoard, 0, 0) == -1) cout << "HaruHaru";
    else cout << "Hing";
}