#include <bits/stdc++.h>

using namespace std;

int main() {
    int R, S;
    cin >> R >> S;
    vector< vector<char> > board(R, vector<char>(S));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < S; j++) {
            cin >> board[i][j];
        }
    }

    int sg = 0, ans = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < S; j++) {
            if (board[i][j] == '.') {
                int cnt = 0;
                if (j > 0) {
                    if (i > 0 && board[i - 1][j - 1] == 'o')
                        cnt++;
                    if (board[i][j - 1] == 'o')
                        cnt++;
                    if (i < R - 1 && board[i + 1][j - 1] == 'o')
                        cnt++;
                }
                if (j < S - 1) {
                    if (i > 0 && board[i - 1][j + 1] == 'o')
                        cnt++;
                    if (board[i][j + 1] == 'o')
                        cnt++;
                    if (i < R - 1 && board[i + 1][j + 1] == 'o')
                        cnt++;
                }
                if (i < R - 1 && board[i + 1][j] == 'o')
                    cnt++;
                if (i > 0 && board[i - 1][j] == 'o')
                    cnt++;
                
                if (sg < cnt)
                    sg = cnt;
            }

            if (board[i][j] == 'o') {
                if (i < R - 1 && board[i + 1][j] == 'o')
                    ans++;
                if (j < S - 1) {
                    if (i > 0 && board[i - 1][j + 1] == 'o')
                        ans++;
                    if (board[i][j + 1] == 'o')
                        ans++;
                    if (i < R - 1 && board[i + 1][j + 1] == 'o')
                        ans++;
                }
            }
        }
    }

    cout << ans + sg;
}