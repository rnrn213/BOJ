#include <bits/stdc++.h>

using namespace std;

int N;
long long cache[100][100];
vector< vector<int> > gameBoard;

void initCache() {
    memset(cache, -1, 100 * 100 * sizeof(int));
}

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        vector<int> temp;
        for (int j = 0; j < N; j++) {
            int jump;
            cin >> jump;
            temp.push_back(jump);
        }
        gameBoard.push_back(temp);
    }
}

long long solve(int y, int x) {
    if (y == N - 1 && x == N - 1) return 1;
    if (y > N - 1 || x > N - 1) return 0;

    long long& ret = cache[y][x];
    if (ret != -1) return ret;
    ret = 0;
    ret += solve(y + gameBoard[y][x], x) + solve(y, x + gameBoard[y][x]);
    return ret;
}

int main() {
    initCache();
    input();
    cout << solve(0, 0);
}