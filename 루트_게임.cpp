#include <bits/stdc++.h>

using namespace std;

int T, N, cache[1000001];

int solve(int num)
{
    if (num == 0) return 0;

    int& ret = cache[num];
    if (ret != -1) return ret;
    ret = 0;

    int i = 1;
    while (i * i <= num)
    {
        ret = max(ret, (int)!solve(num - i * i));
        if (ret) break;
        i++;
    }

    return ret;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    memset(cache, -1, sizeof(cache));
    for (int i = 1; i <= 1000001; i++)
    {
        solve(i);
    }

    cin >> T;
    while (T--)
    {
        cin >> N;
        if (solve(N)) cout << "koosaga\n";
        else cout << "cubelover\n";
    }
}