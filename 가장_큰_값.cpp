#include <bits/stdc++.h>

using namespace std;

const int INF = -987654321;

int N, M, arr[21], cache[21][21];

int solve(int idx, int g)
{
    if (idx == N) return (g == M) ? 0 : INF;
    if (g == M) return 0;

    int& ret = cache[idx][g];
    if (ret != INF) return ret;

    for (int start = idx; start < N; start++)
    {
        int sum = 0;
        for (int end = start; end < N; end++)
        {
            sum += arr[end];
            ret = max(ret, sum + solve(end + 1, g + 1));
        }
    }

    return ret;
}

int main()
{
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            cache[i][j] = INF;
        }
    }

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    cout << solve(0, 0);
}