#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = -1 * pow(10, 16);

int N, M, K, S, T;
vector< pair<int, int> > course[100001];
vector<int> v[100001];
ll dp[100001][11];

ll solve(int idx, int lift)
{
    if (idx == T && lift == 0) return 0;
    if (idx > T && lift == 0) return INF;

    ll& ret = dp[idx][lift];
    if (ret != -1) return ret;
    ret = INF;

    for (int i = 0; i < course[idx].size(); i++)
    {
        for (int j = 0; j <= lift; j++)
        {
            
            ret = max(ret, course[idx][i].second * (j + 1) + solve(course[idx][i].first, lift - j));
        }
    }
    for (int i = 0; i < v[idx].size(); i++)
    {
        if (lift > 0)
            ret = max(ret, solve(v[idx][i], lift - 1));
    }

    return ret;
}

int main()
{
    memset(dp, -1, sizeof(dp));

    cin >> N >> M >> K >> S >> T;
    for (int i = 0; i < M; i++)
    {
        int a, b, t;
        cin >> a >> b >> t;
        course[a].push_back(make_pair(b, t));
        v[b].push_back(a);
    }

    ll ans = solve(S, K);
    if (ans < 0) cout << -1;
    else cout << ans;
}