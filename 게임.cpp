#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int N, M, cache[51][51];
string board[51];
vector<vector<bool>> visited(51, vector<bool>(51, false));

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int solve(int y, int x)
{
    if (board[y][x] == 'H') return 0;

    int& ret = cache[y][x];
    if (ret != -1) return ret;
    ret = 0;

    visited[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int nextY = (board[y][x] - '0') * dy[i] + y,
            nextX = (board[y][x] - '0') * dx[i] + x;
        if ((nextY < 0 || nextY >= N) || (nextX < 0 || nextX >= M))
        {
            ret = max(ret, 1);
            continue;
        }
        if (visited[nextY][nextX])
        {
            ret = INF;
            continue;
        }
        ret = max(ret, 1 + solve(nextY, nextX));
    }
    visited[y][x] = false;

     return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
    }

    int ans = solve(0, 0);
    if (ans >= INF) cout << -1;
    else cout << ans;
}