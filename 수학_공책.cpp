#include <bits/stdc++.h>

using namespace std;

const int INF = -2100000000;

int N, A[2001], B[2001], cache[2001][2001];

int solve(int l, int r)
{
    if (l + r == N) return 0;

    int& ret = cache[l][r];
    if (ret != INF) return ret;
    solve(l + 1, r);
    solve(l, r + 1);

    int x = 0;
    for (int i = l; i < N - r; i++)
    {
        x += A[i] * B[N - 1 - r - (i - l)];
    }

    return ret = x;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        for (int j = 0; j < N; j++)
        {
            cache[i][j] = INF;
        }
    }
    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
    }

    solve(0, 0);

    int ans = INF, B = -1, E = -1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (ans < cache[i][j])
            {
                ans = cache[i][j];
                B = i;
                E = j;
            }
        }
    }

    cout << B << " " << E << "\n" << ans;
}