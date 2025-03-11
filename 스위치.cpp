#include <bits/stdc++.h>

using namespace std;

const int INF = -2100000000;

int N, A[200001], cache[200001][4];

int solve(int idx, int s)
{
    if (idx > N) return 0;

    int& ret = cache[idx][s];
    if (ret != INF) return ret;
    
    if (s == 0)
    {
        ret = A[idx] + solve(idx + 1, 0);
        ret = max(ret, A[idx] + solve(idx + 1, 1));
    }
    else
    {
        ret = 2 * A[idx] + solve(idx + 1, (s + 1) % 4);
        if (s == 3)
            ret = max(ret, 2 * A[idx] + solve(idx + 1, 1));
    }

    return ret;
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cache[i][j] = INF;
        }
    }

    cout << solve(0, 0);
}