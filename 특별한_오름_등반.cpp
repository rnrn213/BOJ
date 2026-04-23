#include <bits/stdc++.h>

using namespace std;

int N, M, board[2001][1001], cache[2001][1001];

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        board[x][y] = 1;
    }

    cache[0][0] = 0;
    for (int i = 1; i <= 2 * N; i++)
    {
        for (int j = 0; j <= min(i, N) - max(0, i - N); j++)
        {
            if (board[i][j]) continue;

            if (j - 1 >= 0) cache[i][j] = cache[i - 1][j - 1];
            if (j + 1 <= i - 1) cache[i][j] = max(cache[i][j], cache[i - 1][j + 1]);
            if (cache[i][j] != -1) cache[i][j] = max(cache[i][j], j);
        }
    }

    cout << cache[2*N][0];
}