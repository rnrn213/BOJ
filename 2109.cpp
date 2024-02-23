#include <bits/stdc++.h>

using namespace std;

int n;
vector< pair<int, int> > dp;

int main()
{
    cin >> n;
    while (n--)
    {
        int p, d;
        cin >> p >> d;
        dp.push_back(make_pair(d, p));
    }
    dp.push_back(make_pair(0, 0));

    sort(dp.begin(), dp.end(), greater<>());

    int money = 0;
    vector<bool> isVisited(dp.size(), false);
    for (int day = dp[0].first; day > 0; day--)
    {
        int maxMoney = 0, maxIdx = -1, i = 0;
        while (i < dp.size() && dp[i].first >= day)
        {
            if (!isVisited[i] && dp[i].second > maxMoney)
            {
                maxIdx = i;
                maxMoney = dp[i].second;
            }
            i++;
        }

        if (maxIdx != -1)
        {
            money += maxMoney;
            isVisited[maxIdx] = true;
        }
    }

    cout << money;
}