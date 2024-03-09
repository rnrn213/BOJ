#include <bits/stdc++.h>

using namespace std;

int N, cache[1001][2][3];

int solve(int idx, int L, int A)
{
    if (L == 2 || A == 3) return 0;
    if (idx == N + 1) return 1;

    int& ret = cache[idx][L][A];
    if (ret != -1) return ret;
    ret = 0;

    return ret += ((solve(idx + 1, L, 0) % 1000000) + (solve(idx + 1, L + 1, 0) % 1000000) + (solve(idx + 1, L, A + 1) % 1000000)) % 1000000;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N;
    
    cout << solve(1, 0, 0);
}