#include <bits/stdc++.h>

using namespace std;

string solve(const vector< vector<char> >& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            string c(1, board[i][j]);
            if (j <= board.size() - 3) {
                for (int k = 0; k < 3; k++) {
                    if (c[0] != board[i][j + k] || board[i][j + k] == '.') {
                        c = '-';
                        break;
                    }
                }

                if (c[0] == board[i][j])
                    return c;
            }
            
            if (i <= board.size() - 3) {
                c = board[i][j];
                for (int k = 0; k < 3; k++) {
                    if (c[0] != board[i + k][j] || board[i + k][j] == '.') {
                        c = '-';
                        break;
                    }
                }

                if (c[0] == board[i][j])
                    return c;
            }     
            
            if (i <= board.size() - 3 && j <= board.size() - 3) {
                c = board[i][j];
                for (int k = 0; k < 3; k++) {
                    if (c[0] != board[i + k][j + k] || board[i + k][j + k] == '.') {
                        c = '-';
                        break;
                    }
                }

                if (c[0] == board[i][j])
                    return c;
            }

            if (i >= 2 && j <= board.size() - 3) {
                c = board[i][j];
                for (int k = 0; k < 3; k++) {
                    if (c[0] != board[i - k][j + k] || board[i - k][j + k] == '.') {
                        c = '-';
                        break;
                    }
                }

                if (c[0] == board[i][j])
                    return c;
            }
        }
    }

    return "ongoing";
}

int main() {
    int N;
    cin >> N;
    vector< vector<char> > board(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        cin.ignore();
        for (int j = 0; j < N; j++) {
            board[i][j] = cin.get();
        }
    }

    cout << solve(board);
}