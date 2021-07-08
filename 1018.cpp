#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<string> board;

vector<string> getChessBoard(char c) {
    vector<string> chessBoard;
    for (int i = 0; i < 8; i++) {
        string s;
        s += c;
        char prevC = c;
        for (int j = 1; j < 8; j++) {
            if (prevC == 'W') s += 'B';
            else s += 'W';
            prevC = s[j];
        }
        chessBoard.push_back(s);
        c = (c == 'W') ? 'B' : 'W';
    }
    return chessBoard;
}

int solve(int y, int x) {
    vector<string> chessBoard1 = getChessBoard('W');
    vector<string> chessBoard2 = getChessBoard('B');

    /*cout << "chessBoard = \n";
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << chessBoard[i][j];
        }
        cout << "\n";
    }*/

    int cnt1 = 0, cnt2 = 0;
    for (int i = y; i < y + 8; i++) {
        for (int j = x; j < x + 8; j++) {
            if (board[i][j] != chessBoard1[i - y][j - x]) cnt1++;
            if (board[i][j] != chessBoard2[i - y][j - x]) cnt2++;
        }
    }
    return min(cnt1, cnt2);
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        board.push_back(s);
    }

    int ans = 65;
    for (int y = 0; y <= N - 8; y++) {
        for (int x = 0; x <= M - 8; x++) {
            ans = min(ans, solve(y, x));
        }
    }
    cout << ans;
}