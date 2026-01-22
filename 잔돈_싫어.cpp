#include <bits/stdc++.h>

using namespace std;

int N, A[100001], cache[100001][501];

int solve(int idx, int remain)
{
    if (idx == N)
    {
        if (remain == 0) return 0;
        else return -2100000000;
    }

    int& ret = cache[idx][remain];
    if (ret != -1) return ret;
    ret = solve(idx + 1, remain);

    if (A[idx] > 500 && A[idx] < 20000) ret = max(ret, A[idx] - 500 + solve(idx + 1, (remain - ((A[idx] - 500) % 500) + 500) % 500));

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