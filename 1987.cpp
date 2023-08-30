#include <bits/stdc++.h>

using namespace std;

int R, C, ans = 1;
vector<string> board(21);
int dx[4] = {0, 0, -1, 1},
    dy[4] = {-1, 1, 0, 0};
vector<bool> visited(26, false);

int solve(int y, int x, int depth) {
    if (visited[board[y][x] - 'A']) {
        if (depth > ans)
            ans = depth - 1;
        return 0;
    }

    visited[board[y][x] - 'A'] = true;

    for (int i = 0; i < 4; i++) {
        if ((y + dy[i] >= 1 && y + dy[i] <= R) &&
              (x + dx[i] >= 0 && x + dx[i] < C))
            solve(y + dy[i], x + dx[i], depth + 1);
    }

    visited[board[y][x] - 'A'] = false;

    return 0;
}

int main() {
    cin >> R >> C;
    for (int i = 1; i <= R; i++) {
        cin >> board[i];
    }

    solve(1, 0, 1);

    cout << ans;
}