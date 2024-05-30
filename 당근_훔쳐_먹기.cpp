#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N, T;
ll w[200001], p[200001];
priority_queue< pair<ll, int> > pq;

int main()
{
    cin >> N >> T;
    for (int i = 1; i <= N; i++)
    {
        cin >> w[i] >> p[i];
        pq.push(make_pair(p[i], i));
    }

    ll ans = 0;
    for (int i = T; i > T - N; i--)
    {
        pair<ll, int> temp = pq.top(); pq.pop();
        ans += w[temp.second] + p[temp.second] * (i - 1);
    }
    cout << ans;
}