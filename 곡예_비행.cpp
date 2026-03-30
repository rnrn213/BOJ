#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = -999999999999;

int N, M, board[1001][1001];
ll cache[1001][1001][2];

ll solve(int y, int x, int d)
{
    if (y == 0 && x == M - 1 && d == 1) return board[y][x];

    ll& ret = cache[y][x][d];
    if (ret != INF) return ret;

    int nextY = y + (1 + (-2 * d)), nextX = x + 1;
    if (nextY >= 0 && nextY < N) ret = board[y][x] + solve(nextY, x, d);
    if (nextX >= 0 && nextX < M) ret = max(ret, board[y][x] + solve(y, nextX, d));

    if (d == 0) ret = max(ret, board[y][x] + solve(y, x, 1));
    

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N >> M;
    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            cache[i][j][0] = cache[i][j][1] = INF;
        }
    }

    cout << solve(0, 0, 0);
}