#include <bits/stdc++.h>

using namespace std;

int N;
vector< pair<int, int> > ST;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int t, s;
        cin >> t >> s;
        if (s > 24) s = 24;
        ST.push_back(make_pair(s, t));
    }

    sort(ST.begin(), ST.end());

    int ans = ST[0].first - ST[0].second, r = 0;
    for (int i = 1; i < N; i++)
    {
        if (ST[i].second > ST[i].first - ST[i - 1].first)
        {
            if (r >= ST[i].second - (ST[i].first - ST[i - 1].first))
            {
                r -= ST[i].second - (ST[i].first - ST[i - 1].first);
            }
            else
            {
                ans -= ST[i].second - (ST[i].first - ST[i - 1].first) - r;
                r = 0;
            }
        }
        else
        {
            r += (ST[i].first - ST[i - 1].first) - ST[i].second;
        }
    }

    if (ans < 0) ans = -1;
    cout << ans;
}