#include <bits/stdc++.h>

using namespace std;

int N, K, importance[1000], studyTime[1000], cache[1000][10000];

int solve(int idx, int t)
{
    if (idx == K) return 0;

    int &ret = cache[idx][t];
    if (ret != -1) return ret;

    ret = solve(idx + 1, t);
    if (t + studyTime[idx] <= N)
    {
        ret = max(ret, importance[idx] + solve(idx + 1, t + studyTime[idx]));
    }

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> importance[i] >> studyTime[i];
    }

    cout << solve(0, 0);
}