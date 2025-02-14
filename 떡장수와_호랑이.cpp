#include <bits/stdc++.h>

using namespace std;

int N, D[1001][10], cache[1001][10];
vector<int> ans, temp;

int solve(int idx, int prev)
{
    if (idx == N)
    {
        ans = temp;
        return 0;
    }

    int& ret = cache[idx][prev];
    if (ret != -1) return ret;
    ret = 0;

    for (int i = 1; i <= 9; i++)
    {
        if (i != prev && D[idx][i] == 1)
        {
            temp.push_back(i);
            solve(idx + 1, i);
            temp.pop_back();
        }
    }

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int a;
            cin >> a;
            D[i][a] = 1;
        }
    }

    solve(0, 0);

    if (ans.size() == 0) cout << -1;
    else
    {
        for (int x : ans)
        {
            cout << x << "\n";
        }
    }
}