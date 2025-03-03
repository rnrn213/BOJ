#include <bits/stdc++.h>

using namespace std;

int N, A[100001], cache[100001][3];

int solve(int idx, int s)
{
    if (idx == N)
    {
        if (s == 1)
            return (A[idx] == 1) ? 1 : -1;
        else if (s == 2)
            return (A[idx] == 2) ? 1 : -1;
        else
            return 0;
    }

    int& ret = cache[idx][s];
    if (ret != -2100000000) return ret;

    if (s == 1)
    {
        int num = (A[idx] == 1) ? 1 : -1;
        ret = max(num, num + solve(idx + 1, s));
    }
    if (s == 2)
    {
        int num = (A[idx] == 2) ? 1 : -1;
        ret = max(num, num + solve(idx + 1, s));
    }

    return ret;
}

int main()
{
    for (int i = 0; i <= 100000; i++)
    {
        for (int j = 1; j <= 2; j++)
        {
            cache[i][j] = -2100000000;
        }
    }

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }

    int ans = -2100000000;
    for (int i = N; i > 0; i--)
    {
        for (int j = 1; j <= 2; j++)
        {
            ans = max(ans, solve(i, j));
        }
    }

    cout << ans;
}