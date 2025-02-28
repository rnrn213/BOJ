#include <bits/stdc++.h>

using namespace std;

int N, A[1001], cache[1001][7];

int solve(int idx, int d)
{
    if (d == 4) return 1;
    if (idx == N) return 0;

    int& ret = cache[idx][d];
    if (ret != -1) return ret;

    return ret = max(solve(idx + 1, d), solve(idx + 1, (d + A[idx]) % 7));
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    if (solve(0, 0)) cout << "YES";
    else cout << "NO";
}