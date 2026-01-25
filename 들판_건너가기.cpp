#include <bits/stdc++.h>

using namespace std;

int N, A[100001], cache[100001][101];

int solve(int idx, int prev)
{
    if (idx == N) return 0;

    int& ret = cache[idx][prev];
    if (ret != -1) return ret;
    ret = solve(idx + 1, prev);

    if (prev > 0)
        ret = max(ret, (int)pow(A[idx] - prev, 2) + solve(idx + 1, A[idx]));
    else
        ret = max(ret, solve(idx + 1, A[idx]));
    
    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    cout << solve(0, 0); 
}