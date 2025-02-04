#include <bits/stdc++.h>

using namespace std;

const int INF = 1000000000;

int n, k, cache[101][10001];
vector<int> c;

int solve(int idx, int won)
{
    if (idx == c.size())
    {
        if (won > 0) return INF;
        else return 0;
    }
    if (won == 0) return 0;

    int& ret = cache[idx][won];
    if (ret != -1) return ret;
    ret = INF;

    int a = won / c[idx];

    for (int i = a; i >= 0; i--)
    {
        ret = min(ret, i + solve(idx + 1, won - i * c[idx]));
    }

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        c.push_back(num);
    }

    c.erase(unique(c.begin(), c.end()), c.end());

    sort(c.begin(), c.end(), greater<>());

    int ans = solve(0, k);

    if (ans == INF) cout << -1;
    else cout << ans;
}