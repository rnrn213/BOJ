#include <bits/stdc++.h>

using namespace std;

int N, cache[1500001], T[1500001], P[1500001];

int solve(int idx)
{
    if (idx == N + 1) return 0;

    int& ret = cache[idx];
    if (ret != -1) return ret;
    ret = 0;

    if (idx + T[idx] <= N + 1) 
        ret = max(ret, P[idx] + solve(idx + T[idx]));
    ret = max(ret, solve(idx + 1));

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(cache, -1, sizeof(cache));

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> T[i] >> P[i];
    }

    cout << solve(1);
    
}