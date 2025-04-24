#include <bits/stdc++.h>

using namespace std;

int N, M, K, cache[11][11][6], len;
string board[11], s;

int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};

int solve(int y, int x, int length)
{
    if (length == len - 1 && board[y][x] == s[length]) return 1;

    int& ret = cache[y][x][length];
    if (ret != -1) return ret;
    ret = 0;

    for (int i = 0; i < 8; i++)
    {
        int nextY = (y + dy[i] + N) % N, nextX = (x + dx[i] + M) % M;
        if (board[nextY][nextX] == s[length + 1])
            ret += solve(nextY, nextX, length + 1);
    }

    return ret;
}

int main()
{
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
    }
    for (int i = 0; i < K; i++)
    {
        memset(cache, -1, sizeof(cache));

        cin >> s;
        len = s.size();
        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (board[i][j] == s[0])
                    ans += solve(i, j, 0);
            }
        }
        cout << ans << "\n";
    }
}