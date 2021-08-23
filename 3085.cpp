#include <bits/stdc++.h>

using namespace std;

int getCanEatCandyRow(const vector< vector<char> >& board, int i) {
    char prev = board[i][0];
    int ret = 1, count = 1;
    for (int j = 1; j < board.size(); j++) {
        if (prev == board[i][j]) count++;
        else {
            prev = board[i][j];
            if (count > ret) ret = count;
            count = 1;
        }
    }
    if (count > ret) ret = count;
    return ret;
}

int getCanEatCandyColumn(const vector< vector<char> >& board, int j) {
    char prev = board[0][j];
    int ret = 1, count = 1;
    for (int i = 1; i < board.size(); i++) {
        if (prev == board[i][j]) count++;
        else {
            prev = board[i][j];
            if (count > ret) ret = count;
            count = 1;
        }
    }
    if (count > ret) ret = count;
    return ret;
}

int main() {
    int N;
    cin >> N;
    vector< vector<char> > board(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    int maxCandy = 1;
    for (int i = 0; i < N; i++) {
        int rowCandy = getCanEatCandyRow(board, i);
        int columnCandy = getCanEatCandyColumn(board, i);
        maxCandy = (maxCandy < rowCandy) ? rowCandy : maxCandy;
        maxCandy = (maxCandy < columnCandy) ? columnCandy : maxCandy;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j < N - 1 && board[i][j] != board[i][j + 1]) {
                char temp = board[i][j];
                board[i][j] = board[i][j + 1];
                board[i][j + 1] = temp;

                int candy = max({getCanEatCandyRow(board, i), getCanEatCandyColumn(board, j), getCanEatCandyColumn(board, j + 1)});
                maxCandy = (maxCandy < candy) ? candy : maxCandy;  

                board[i][j + 1] = board[i][j];
                board[i][j] = temp;            
            }

            if (i < N - 1 && board[i][j] != board[i + 1][j]) {
                char temp = board[i][j];
                board[i][j] = board[i + 1][j];
                board[i + 1][j] = temp;

                int candy = max({getCanEatCandyColumn(board, j), getCanEatCandyRow(board, i), getCanEatCandyRow(board, i + 1)});
                maxCandy = (maxCandy < candy) ? candy : maxCandy;

                board[i + 1][j] = board[i][j];
                board[i][j] = temp;
            }
        }
    }

    cout << maxCandy;
}