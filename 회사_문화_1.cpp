#include <bits/stdc++.h>

using namespace std;

int n, m, arr[100001], w[100001], cache[100001];
vector<int> v[100001];

void solve(int idx, int value)
{
    cache[idx] = value + w[idx];

    for (int i = 0; i < v[idx].size(); i++)
    {
        solve(v[idx][i], value + w[idx]);
    }

    return;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        v[num].push_back(i);
    }
    for (int i = 0; i < m; i++)
    {
        int e, ww;
        cin >> e >> ww;
        w[e] += ww;
    }

    solve(1, 0);

    for (int i = 1; i <= n; i++)
    {
        cout << cache[i] << " ";
    }
}