#include <bits/stdc++.h>

using namespace std;

int n, cache[101][101], m;
vector<pair<int, int>> v[101];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int c, t;
        cin >> c >> t;
        v[c].push_back(make_pair(i, t));
        if (c > m)
            m = c;
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            for (int k = 0; k < v[i + 1].size(); k++)
            {
                cache[i + 1][k] = max(cache[i + 1][k], cache[i][j] + v[i][j].second + (int)pow(v[i + 1][k].first - v[i][j].first, 2));
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < v[m].size(); i++)
    {
        if (ans < cache[m][i] + v[m][i].second)
            ans = cache[m][i] + v[m][i].second;
    }
    cout << ans;
}