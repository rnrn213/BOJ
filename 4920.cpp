#include <bits/stdc++.h>

using namespace std;

int main() {
    int T = 1;
    while (true) {
        int N; 
        cin >> N;
        if (N == 0)
            break;
        
        vector< vector<int> > board(N, vector<int>(N));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> board[i][j];
            }
        }

        int maxSum = -5000000;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (j < N - 3 && 
                    board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i][j + 3] > maxSum)
                    maxSum = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i][j + 3];
                if (i < N - 3 &&
                    board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 3][j] > maxSum)
                    maxSum = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 3][j];
                
                if ((i < N - 1 && j < N - 2) && 
                    board[i][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i + 1][j + 2] > maxSum)
                    maxSum = board[i][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i + 1][j + 2];
                if ((i < N - 2 && j > 0) && 
                    board[i][j] + board[i + 1][j] + board[i + 1][j - 1] + board[i + 2][j - 1] > maxSum)
                    maxSum = board[i][j] + board[i + 1][j] + board[i + 1][j - 1] + board[i + 2][j - 1];

                if ((i < N - 1 && j < N - 2) &&
                    board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j + 2] > maxSum)
                    maxSum = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j + 2];
                if ((i < N - 2 && j > 0) &&
                    board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 2][j - 1] > maxSum)
                    maxSum = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 2][j - 1];
                if ((i < N - 1 && j < N - 2) &&
                    board[i][j] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j + 2] > maxSum)
                    maxSum = board[i][j] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j + 2];
                if ((i < N - 2 && j > 0) &&
                    board[i][j] + board[i][j - 1] + board[i + 1][j - 1] + board[i + 2][j - 1] > maxSum)
                    maxSum = board[i][j] + board[i][j - 1] + board[i + 1][j - 1] + board[i + 2][j - 1];
                
                if ((i < N - 1 && j < N - 2) &&
                    board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j + 1] > maxSum)
                    maxSum = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j + 1];
                if ((i < N - 2 && j > 0) &&
                    board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 1][j - 1] > maxSum)
                    maxSum = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 1][j - 1];
                if ((i > 0 && j < N - 2) &&
                    board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i - 1][j + 1] > maxSum)
                    maxSum = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i - 1][j + 1];
                if ((i < N - 2 && j < N - 1) &&
                    board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 1][j + 1] > maxSum)
                    maxSum = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 1][j + 1];
                
                if ((i < N - 1 && j < N - 1) &&
                    board[i][j] + board[i][j + 1] + board[i + 1][j] + board[i + 1][j + 1] > maxSum)
                    maxSum = board[i][j] + board[i][j + 1] + board[i + 1][j] + board[i + 1][j + 1];


            }
        }

        cout << T << ". " << maxSum << "\n";
        T++;
    }
}