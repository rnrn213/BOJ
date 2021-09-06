#include <bits/stdc++.h>

using namespace std;

vector< vector<char> > board(7, vector<char>(7));

void inputBoard() {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            board[i][j] = cin.get();
        }
        cin.ignore();
    }
}

int solve() {
    int cnt = 0;

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (board[i][j] == 'o') {
                if (i > 1 && board[i - 1][j] == 'o' && board[i - 2][j] == '.')
                    cnt++;
                if (i < 5 && board[i + 1][j] == 'o' && board[i + 2][j] == '.')
                    cnt++;
                if (j > 1 && board[i][j - 1] == 'o' && board[i][j - 2] == '.')
                    cnt++;
                if (j < 5 && board[i][j + 1] == 'o' && board[i][j + 2] == '.')
                    cnt++;
            }
        }
    }

    return cnt;
}

int main() {
    inputBoard();
    cout << solve();
}