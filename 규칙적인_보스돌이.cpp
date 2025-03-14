#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N, M, K, Q[14], cache[50][50][14][901], l = -1;
ll D[50], P[14];

int solve(int idx, int cnt, int b, int t)
{
    if (cnt == M && l != idx) return 0;
    if (idx == N) return 0;

    int& ret = cache[idx][cnt][b][t];
    if (ret != -1) return ret;
    ret = solve(idx + 1, cnt, 0, 900);

    for (int i = b; i < K; i++)
    {
        if (P[i] % D[idx] == 0)
        {
            if (P[i] / D[idx] <= t)
            {
                if (t == 900)
                {
                    l = idx;
                    ret = max(ret, Q[i] + solve(idx, cnt + 1, i + 1, t - P[i] / D[idx]));
                    l = -1;
                }
                else
                    ret = max(ret, Q[i] + solve(idx, cnt, i + 1, t - P[i] / D[idx]));
            }
        }
        else
        {
            if (P[i] / D[idx] + 1 <= t)
            {
                if (t == 900)
                {
                    l = idx;
                    ret = max(ret, Q[i] + solve(idx, cnt + 1, i + 1, t - (P[i] / D[idx] + 1)));
                    l = -1;
                }
                else
                    ret = max(ret, Q[i] + solve(idx, cnt, i + 1, t - (P[i] / D[idx] + 1)));
            }
        }
    }

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> D[i];
    }
    for (int i = 0; i < K; i++)
    {
        cin >> P[i] >> Q[i];
    }

    cout << solve(0, 0, 0, 900);
}