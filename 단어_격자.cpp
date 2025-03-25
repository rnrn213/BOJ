#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int H, W, L;
char board[201][201];
string word;
ll cache[201][201][101];

int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};

ll solve(int y, int x, int len)
{
    if (len == L - 1) return 1;

    ll& ret = cache[y][x][len];
    if (ret != -1) return ret;
    ret = 0;

    for (int i = 0; i < 8; i++)
    {
        int nextY = y + dy[i], nextX = x + dx[i];
        if ((nextY >= 0 && nextY < H) && (nextX >= 0 && nextX < W))
        {
            if (board[nextY][nextX] == word[len + 1])
                ret += solve(nextY, nextX, len + 1);
        }
    }

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> H >> W >> L;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> board[i][j];
        }
    }
    cin >> word;

    ll ans = 0;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (board[i][j] == word[0])
                ans += solve(i, j, 0);
        }
    }

    cout << ans;
}