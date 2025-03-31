#include <bits/stdc++.h>

using namespace std;

int N, x, L[101], C[101], cache[10001][101];

int solve(int len, int idx)
{
    if (len == 0) return 1;
    if (idx == N) return 0;

    int& ret = cache[len][idx];
    if (ret != -1) return ret;
    ret = 0;

    for (int i = 0; i <= C[idx]; i++)
    {
        if (len - L[idx] * i < 0) break;
        ret += solve(len - L[idx] * i, idx + 1);
    }

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));
    
    cin >> N >> x;
    for (int i = 0; i < N; i++)
    {
        cin >> L[i] >> C[i];
    }

    cout << solve(x, 0);
}