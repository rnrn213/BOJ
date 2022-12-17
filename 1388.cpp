#include <bits/stdc++.h>

using namespace std;

int N, M;
string A[50];
bool visited[50][50];

void layBoard(int i, int j) {
    visited[i][j] = true;

    if (A[i][j] == '-') {
        if (j + 1 < M && A[i][j + 1] == '-')
            layBoard(i, j + 1);
        else
            return;
    }
    else {
        if (i + 1 < N && A[i + 1][j] == '|')
            layBoard(i + 1, j);
        else
            return;
    }

    return;
}

int main() {
    memset(visited, false, sizeof(visited));

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j]) {
                layBoard(i, j);
                ans++;
            }
        }
    }

    cout << ans;
}