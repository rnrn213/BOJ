#include <bits/stdc++.h>

using namespace std;

int N;
vector< pair<int, int> > ST;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int s, t;
        cin >> s >> t;
        ST.push_back(make_pair(s, t));
    }

    sort(ST.begin(), ST.end());

    int ans = 1;
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(ST[0].second);
    for (int i = 1; i < N; i++)
    {
        if (ST[i].first >= pq.top())
        {
            pq.pop();
        }
        else
        {
            ans++;
        }

        pq.push(ST[i].second);
    }

    cout << ans;
}