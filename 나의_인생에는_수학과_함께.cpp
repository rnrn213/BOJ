#include <bits/stdc++.h>

using namespace std;

int N, cache[6][6][3126];
char board[6][6];

void initCache(int num)
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            for (int k = 0; k < 3126; k++)
            {
                cache[i][j][k] = num;
            }
        }
    }
}

int solveMax(int y, int x, int num)
{
    if (y == N && x == N)
        return num;
    
    int& ret = cache[y][x][num];
    if (ret != -1000000000) return ret;

    if (y + 1 <= N)
    {
        if (board[y + 1][x] == '+')
        {
            if (y + 2 <= N)
                ret = max(ret, solveMax(y + 2, x, num + (board[y + 2][x] - '0')));
            if (x + 1 <= N)
                ret = max(ret, solveMax(y + 1, x + 1, num + (board[y + 1][x + 1] - '0')));
        }
        if (board[y + 1][x] == '-')
        {
            if (y + 2 <= N)
                ret = max(ret, solveMax(y + 2, x, num - (board[y + 2][x] - '0')));
            if (x + 1 <= N)
                ret = max(ret, solveMax(y + 1, x + 1, num - (board[y + 1][x + 1] - '0')));
        }
        if (board[y + 1][x] == '*')
        {
            if (y + 2 <= N)
                ret = max(ret, solveMax(y + 2, x, num * (board[y + 2][x] - '0')));
            if (x + 1 <= N)
                ret = max(ret, solveMax(y + 1, x + 1, num * (board[y + 1][x + 1] - '0')));
        }
    }
    if (x + 1 <= N)
    {
        if (board[y][x + 1] == '+')
        {
            if (x + 2 <= N)
                ret = max(ret, solveMax(y, x + 2, num + (board[y][x + 2] - '0')));
            if (y + 1 <= N)
                ret = max(ret, solveMax(y + 1, x + 1, num + (board[y + 1][x + 1] - '0')));
        }
        if (board[y][x + 1] == '-')
        {
            if (x + 2 <= N)
                ret = max(ret, solveMax(y, x + 2, num - (board[y][x + 2] - '0')));
            if (y + 1 <= N)
                ret = max(ret, solveMax(y + 1, x + 1, num - (board[y + 1][x + 1] - '0')));
        }
        if (board[y][x + 1] == '*')
        {
            if (x + 2 <= N)
                ret = max(ret, solveMax(y, x + 2, num * (board[y][x + 2] - '0')));
            if (y + 1 <= N)
                ret = max(ret, solveMax(y + 1, x + 1, num * (board[y + 1][x + 1] - '0')));
        }
    }

    return ret;
}

int solveMin(int y, int x, int num)
{
    if (y == N && x == N)
        return num;
    
    int& ret = cache[y][x][num];
    if (ret != 1000000000) return ret;

    if (y + 1 <= N)
    {
        if (board[y + 1][x] == '+')
        {
            if (y + 2 <= N)
                ret = min(ret, solveMin(y + 2, x, num + (board[y + 2][x] - '0')));
            if (x + 1 <= N)
                ret = min(ret, solveMin(y + 1, x + 1, num + (board[y + 1][x + 1] - '0')));
        }
        if (board[y + 1][x] == '-')
        {
            if (y + 2 <= N)
                ret = min(ret, solveMin(y + 2, x, num - (board[y + 2][x] - '0')));
            if (x + 1 <= N)
                ret = min(ret, solveMin(y + 1, x + 1, num - (board[y + 1][x + 1] - '0')));
        }
        if (board[y + 1][x] == '*')
        {
            if (y + 2 <= N)
                ret = min(ret, solveMin(y + 2, x, num * (board[y + 2][x] - '0')));
            if (x + 1 <= N)
                ret = min(ret, solveMin(y + 1, x + 1, num * (board[y + 1][x + 1] - '0')));
        }
    }
    if (x + 1 <= N)
    {
        if (board[y][x + 1] == '+')
        {
            if (x + 2 <= N)
                ret = min(ret, solveMin(y, x + 2, num + (board[y][x + 2] - '0')));
            if (y + 1 <= N)
                ret = min(ret, solveMin(y + 1, x + 1, num + (board[y + 1][x + 1] - '0')));
        }
        if (board[y][x + 1] == '-')
        {
            if (x + 2 <= N)
                ret = min(ret, solveMin(y, x + 2, num - (board[y][x + 2] - '0')));
            if (y + 1 <= N)
                ret = min(ret, solveMin(y + 1, x + 1, num - (board[y + 1][x + 1] - '0')));
        }
        if (board[y][x + 1] == '*')
        {
            if (x + 2 <= N)
                ret = min(ret, solveMin(y, x + 2, num * (board[y][x + 2] - '0')));
            if (y + 1 <= N)
                ret = min(ret, solveMin(y + 1, x + 1, num * (board[y + 1][x + 1] - '0')));
        }
    }

    return ret;
}

int main()
{
    initCache(-1000000000);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> board[i][j];
        }
    }

    int maxAns = solveMax(1, 1, board[1][1] - '0');

    initCache(1000000000);

    int minAns = solveMin(1, 1, board[1][1] - '0');

    cout << maxAns << " " << minAns;
}