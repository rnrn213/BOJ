#include <bits/stdc++.h>

using namespace std;

int R, C, board[501][501], ans[501][501];
pair<int, int> cache[501][501];

int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};

pair<int, int> solve(int y, int x)
{
    pair<int, int>& ret = cache[y][x];
    if (ret.first != 0 && ret.second != 0) return ret;
    ret.first = y;
    ret.second = x;

    int minY = y, minX = x;
    for (int i = 0; i < 8; i++)
    {
        int nextY = y + dy[i], nextX = x + dx[i];
        if ((nextY == 0 || nextY > R) || (nextX == 0 || nextX > C))
            continue;
        
        if (board[minY][minX] > board[nextY][nextX])
        {
            minY = nextY;
            minX = nextX;
        }
    }

    if (minY != y || minX != x)
        ret = solve(minY, minX);
    
    return ret;
}

int main()
{
    cin >> R >> C;
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1 ; j <= C; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            pair<int, int> p = solve(i, j);
            ans[p.first][p.second]++;
        }
    }

    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}