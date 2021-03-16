#include <bits/stdc++.h>

using namespace std;

int T, N, M;
int numberOfCases[30][30];

void input() {
    cin >> T;
}

void initNumberOfCases() {
    for (int i = 0; i < 30; i++) {
        numberOfCases[0][i] = i + 1;
    }
    for (int i = 1; i < 30; i++) {
        numberOfCases[i][i] = 1;
    }
    for (int i = 1; i < 30; i++) {
        for (int j = i + 1; j < 30; j++) {
            numberOfCases[i][j] = numberOfCases[i][j - 1] + numberOfCases[i - 1][j - 1];
        }
    }
}

void solve() {
    initNumberOfCases();
    for (int i = 0; i < T; i++) {
        cin >> N >> M;
        cout << numberOfCases[N - 1][M - 1] << "\n";
    }
}

int main() {
    input();
    solve();
}