#include <bits/stdc++.h>

using namespace std;

int N, L[1001], R[1001], cache[1001][1101];

int solve(int idx, int p)
{
    if (idx == N) return 0;
    if (p < 0 || p > 1001) return 2;

    int& ret = cache[idx][p];
    if (ret != -1) return ret;
    ret = (L[idx] <= p && p <= R[idx]) ? 0 : 1;

    return ret += min({solve(idx + 1, p - 1), solve(idx + 1, p + 1), solve(idx + 1, p)});
}

int main()
{
    memset(cache, -1, sizeof(cache));
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> L[i] >> R[i];
    }

    int ans = N;
    for (int i = 0; i <= 1001; i++)
    {
        ans = min(ans, solve(0, i));
    }

    if (ans <= 1) cout << "World Champion";
    else cout << "Surrender";
}