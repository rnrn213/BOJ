#include <bits/stdc++.h>

using namespace std;

int N, K, A[101], B[101], cache[101][5050];

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i] >> B[i];
    }

    cache[0][1] = 0;
    for (int i = 0; i < K; i++)
    {
        for (int j = 1; j < 5050; j++)
        {
            if (cache[i][j] == -1) continue;

            cache[i + 1][j] = max(cache[i + 1][j], j + cache[i][j]);

            for (int m = 1; m <= N; m++)
            {
                if (cache[i][j] >= A[m])
                {
                    cache[i + 1][j + B[m]] = max(cache[i + 1][j + B[m]], cache[i][j] - A[m]);
                }
            }
        }
    }
    
    int ans = 0;
    for (int j = 1; j < 5050; j++)
    {
        if (cache[K][j] > ans)
            ans = cache[K][j];
    }
    cout << ans;
}