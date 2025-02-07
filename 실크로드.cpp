#include <bits/stdc++.h>

using namespace std;

const int INF = 2100000000;

int N, M, D[1001], C[1001], cache[1001][1001];

int solve(int idx, int day)
{
    if (idx > N) return 0;
    if (day > M) return INF;

    int& ret = cache[idx][day];
    if (ret != -1) return ret;

    return ret = min(D[idx] * C[day] + solve(idx + 1, day + 1), solve(idx, day + 1));
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> D[i];
    }
    for (int i = 1; i <= M; i++)
    {
        cin >> C[i];
    }

    cout << solve(1, 1);
}