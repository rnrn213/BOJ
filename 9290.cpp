#include <bits/stdc++.h>

using namespace std;

void getAnswer(vector< vector<char> >& gameBoard, char c) {
    int namGu = 0, blank = 0;

    for (int i = 0; i < 3; i++) {
        namGu = 0, blank = 0;
        for (int j = 0; j < 3; j++) {
            if (gameBoard[i][j] == c) namGu++;
            if (gameBoard[i][j] == '-') blank++;
        }
        if (namGu == 2 && blank == 1) {
            for (int j = 0; j < 3; j++) {
                if (gameBoard[i][j] == '-') {
                    gameBoard[i][j] = c;
                    return;
                }
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        namGu = 0, blank = 0;
        for (int j = 0; j < 3; j++) {
            if (gameBoard[j][i] == c) namGu++;
            if (gameBoard[j][i] == '-') blank++;
        }
        if (namGu == 2 && blank == 1) {
            for (int j = 0; j < 3; j++) {
                if (gameBoard[j][i] == '-') {
                    gameBoard[j][i] = c;
                    return;
                }
            }
        }
    }

    namGu = 0, blank = 0;
    for (int i = 0; i < 3; i++) {
        if (gameBoard[i][i] == c) namGu++;
        if (gameBoard[i][i] == '-') blank++;
    }
    if (namGu == 2 && blank == 1) {
        for (int i = 0; i < 3; i++) {
            if (gameBoard[i][i] == '-') {
                gameBoard[i][i] = c;
                return;
            }
        }
    }

    namGu = 0, blank = 0;
    for (int i = 0; i < 3; i++) {
        if (gameBoard[i][2 - i] == c) namGu++;
        if (gameBoard[i][2 - i] == '-') blank++;
    }
    if (namGu == 2 && blank == 1) {
        for (int i = 0; i < 3; i++) {
            if (gameBoard[i][2 - i] == '-') {
                gameBoard[i][2 - i] = c;
                return;
            }
        }
    }
    return;
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        vector< vector<char> > gameBoard(3, vector<char>(3));
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                cin >> gameBoard[j][k];
            }
        }
        char c;
        cin >> c;

        getAnswer(gameBoard, c);

        cout << "Case " << i << ":\n";
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                cout << gameBoard[j][k];
            }
            cout << "\n";
        }
    }
}