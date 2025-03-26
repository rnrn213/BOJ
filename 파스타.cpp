#include <bits/stdc++.h>

using namespace std;

int N, K, arr[101], cache[101][3][3][3];

int solve(int idx, int t, int c, int b)
{
    if (t == 3 || c == 3 || b == 3) return 0;
    if (idx > N) return 1;

    int& ret = cache[idx][t][c][b];
    if (ret != -1) return ret;
    
    if (arr[idx] == 1) ret = solve(idx + 1, t + 1, 0, 0) % 10000;
    else if (arr[idx] == 2) ret = solve(idx + 1, 0, c + 1, 0) % 10000;
    else if (arr[idx] == 3) ret = solve(idx + 1, 0, 0, b + 1) % 10000;
    else
    {
        ret = (solve(idx + 1, t + 1, 0, 0) + solve(idx + 1, 0, c + 1, 0) + solve(idx + 1, 0, 0, b + 1)) % 10000;
    }

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N >> K;
    for (int i = 0; i < K; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a] = b;
    }

    cout << solve(1, 0, 0, 0);
}