#include <bits/stdc++.h>

using namespace std;

int N, arr[1001], cache[1001][2];

int solve1(int idx)
{
    if (idx == N - 1) return 1;

    int& ret = cache[idx][0];
    if (ret != -1) return ret;
    ret = 1;

    for (int i = idx + 1; i < N; i++)
    {
        if (arr[idx] < arr[i])
            ret = max(ret, 1 + solve1(i));
    }

    return ret;
}

int solve2(int idx)
{
    if (idx == 0) return 1;

    int& ret = cache[idx][1];
    if (ret != -1) return ret;
    ret = 1;

    for (int i = idx - 1; i >= 0; i--)
    {
        if (arr[idx] < arr[i])
            ret = max(ret, 1 + solve2(i));
    }

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++)
    {
        solve1(i);
        solve2(i);
    }

    int ans = 1;
    for (int i = 0; i < N; i++)
    {
        if (ans < cache[i][0])
            ans = cache[i][0];
        if (ans < cache[i][1])
            ans = cache[i][1];
        if (ans < cache[i][0] + cache[i][1] - 1)
            ans = cache[i][0] + cache[i][1] - 1;
    }
    cout << ans;
}