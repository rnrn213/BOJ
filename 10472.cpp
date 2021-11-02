#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > flip = { {0, 1, 3}, {0, 1, 2, 4}, {1, 2, 5}, {0, 3, 4, 6}, {1, 3, 4, 5, 7}, {2, 4, 5, 8}, {3, 6, 7}, {4, 6, 7, 8}, {5, 7, 8} };

bool isEqual(const vector<int>& targetBoard, const vector<int>& board) {
    if (targetBoard == board)
        return true;
    else
        return false;
}

void clickBoard(vector<int>& board, int idx) {
    for (int i = 0; i < flip[idx].size(); i++) {
        board[flip[idx][i]]++;
        if (board[flip[idx][i]] == 2)
            board[flip[idx][i]] = 0;
    }
}

int solve(const vector<int>& targetBoard, vector<int>& board, int idx) {
    if (idx == 9)
        return isEqual(targetBoard, board) ? 0 : 9999;
    
    int ret = 9999;
    for (int i = 0; i < 2; i++) {
        ret = min(ret, i + solve(targetBoard, board, idx + 1));
        clickBoard(board, idx);
    }
    
    return ret;
}

int main() {
    int P;
    cin >> P;
    while (P) {
        vector<int> targetBoard(9), board(9, 0);
        for (int i = 0; i < 9; i++) {
            char c;
            cin >> c;
            if (c == '*')
                targetBoard[i] = 1;
            else
                targetBoard[i] = 0;
        }

        cout << solve(targetBoard, board, 0) << "\n";

        P--;
    }
}