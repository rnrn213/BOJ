#include <bits/stdc++.h>

using namespace std;

int N;
vector< pair<int, int> > dw(1000);
vector<bool> isFinished(1000, false);

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> dw[i].first >> dw[i].second;
    }

    sort(dw.begin(), dw.begin() + N, greater<>());

    int maxDay = dw[0].first, maxW = 0, maxIdx = -1, ans = 0;
    for (int i = maxDay; i > 0; i--)
    {
        for (int j = 0; j < N; j++)
        {
            if (dw[j].first < i)
            {
                break;
            }

            if (dw[j].second > maxW && !isFinished[j])
            {
                maxW = dw[j].second;
                maxIdx = j;
            }
        }

        ans += maxW;
        if (maxIdx != -1)
        {
            isFinished[maxIdx] = true;
        }
        maxW = 0;
        maxIdx = -1;
    }

    cout << ans;
}