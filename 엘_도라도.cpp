#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k, arr[101];
ll cache[101][101];

ll solve(int idx, int cnt)
{
    if (cnt == k) return 1;
    if (idx == n - 1) return 0;

    ll& ret = cache[idx][cnt];
    if (ret != -1) return ret;
    ret = 0;

    for (int i = idx + 1; i < n; i++)
    {
        if (arr[idx] < arr[i])
            ret += solve(i, cnt + 1);
    }

    return ret;
}

int main()
{
    while (cin >> n >> k)
    {
        memset(cache, -1, sizeof(cache));

        if (n == 0 && k == 0) break;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += solve(i, 1);
        }

        cout << ans << "\n";
    }
}