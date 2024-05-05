#include <bits/stdc++.h>

using namespace std;

int N, t[501], dp[501];
vector<int> v[501];

int solve(int idx)
{
    int& ret = dp[idx];
    if (ret != -1) return ret;
    ret = 2100000000;

    int time = 0;
    for (int i = 0; i < v[idx].size(); i++)
    {
        time = max(time, solve(v[idx][i]));
    }

    return ret = t[idx] + time;
}

int main()
{
    memset(dp, -1, sizeof(dp));

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> t[i];
        while (true)
        {
            int num;
            cin >> num;
            if (num == -1) break;
            v[i].push_back(num);
        }
    }

    for (int i = 1; i <= N; i++)
    {
        solve(i);
        cout << dp[i] << '\n';
    }
}