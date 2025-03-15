#include <bits/stdc++.h>

using namespace std;

const int INF = -2100000000;

int N, S, T, arr[201], cache[201][202];

int solve(int idx, int turn)
{
    if (idx > N) return 0;
    if (turn == T) return INF;

    int& ret = cache[idx][turn];
    if (ret != INF) return ret;
    
    for (int i = 1; i <= S; i++)
    {
        ret = max(ret, arr[idx] + solve(idx + i, turn + 1));
    }

    return ret;
}

int main()
{
    while (cin >> N)
    {
        if (N == 0) break;

        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; j < 202; j++)
            {
                cache[i][j] = INF;
            }
        }

        cin >> S >> T;
        for (int i = 1; i <= N; i++)
        {
            cin >> arr[i];
        }

        cout << solve(0, 0) << "\n";
    }
}