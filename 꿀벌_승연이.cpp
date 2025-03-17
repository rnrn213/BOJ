#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int N, M, K, arr[1003][1003];
long long cache[1003][1003];

int dx[2][3] = {{-1, 0, 1}, {-1, -1, 0}};
int dy[2][3] = {{0, -1, -1}, {0, -1, -1}};

int main()
{

    cin >> N >> M >> K;
    for (int i = 0; i < K; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[x][y] = 1;
    }

    cache[1][1] = 1;
    for (int y = 1; y <= M; y++)
    {
        for (int x = 1; x <= N; x++)
        {
            for (int i = 0; i < 3; i++)
            {
                int prevX = x + dx[y % 2][i], prevY = y + dy[y % 2][i];
                if ((prevX < 1 || prevX > N) || (prevY < 1 || prevY > M)) continue;
                if (arr[prevX][prevY] == 1) continue;

                cache[x][y] += cache[prevX][prevY];
            }
            cache[x][y] %= MOD;
        }
    }

    cout << cache[N][M];
}