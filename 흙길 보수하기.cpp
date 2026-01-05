#include <bits/stdc++.h>

using namespace std;

int N, L;
pair<int, int> p[10001];

int main()
{
    cin >> N >> L;
    for (int i = 0; i < N; i++)
    {
        cin >> p[i].first >> p[i].second;
    }

    sort(p, p + N);

    int ans = 0, s = -1;
    for (int i = 0; i < N; i++)
    {
        int len = p[i].second - max(p[i].first, s);
        if (len <= 0) continue;
        int cnt = (len % L > 0) ? len / L + 1 : len / L;
        ans += cnt;
        s = max(p[i].first, s) + cnt * L;
    }

    cout << ans;
}
