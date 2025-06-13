#include <bits/stdc++.h>

using namespace std;

int N, M, arr[21][301], cache[21][301];

int solve(int idx, int money)
{
    if (idx == M) return 0;

    int& ret = cache[idx][money];
    if (ret != -1) return ret;
    ret = 0;

    for (int i = 0; i <= money; i++)
    {
        ret = max(ret, arr[idx][i] + solve(idx + 1, money - i));
    }

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int p;
        cin >> p;
        for (int j = 0; j < M; j++)
        {
            cin >> arr[j][p];
        }
    }

    cout << solve(0, N) << "\n";
    int ans = solve(0, N);
    int money = N;
    for (int i = 1; i < M; i++)
    {
        for (int j = 0; j <= money; j++)
        {
            if (ans == arr[i - 1][j] + cache[i][money - j])
            {
                cout << j << " ";
                ans = cache[i][money - j];
                money -= j;
                break;
            }
        }
    }
    cout << money;
}