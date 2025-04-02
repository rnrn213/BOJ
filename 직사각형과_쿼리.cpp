#include <bits/stdc++.h>

using namespace std;

int N, board[301][301], Q, cache[301][301][11];

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 1; k <= 10; k++)
            {
                cache[i][j][k] = cache[i - 1][j][k] + cache[i][j - 1][k] - cache[i - 1][j - 1][k];
            }

            cache[i][j][board[i][j]]++;
        }
    }

    cin >> Q;
    while (Q--)
    {
        int x1, y1, x2, y2, cnt = 0;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int i = 1; i <= 10; i++)
        {
            if (cache[x2][y2][i] - cache[x1 - 1][y2][i] - cache[x2][y1 - 1][i] + cache[x1 - 1][y1 - 1][i] > 0)
                cnt++;
        }
        cout << cnt << "\n";
    }
}