#include <bits/stdc++.h>

using namespace std;

int N, H, cnt1[500002], cnt2[500002];

int main()
{
    cin >> N >> H;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        if (i % 2 == 0)
        {
            cnt1[num]++;
        }
        else
        {
            cnt2[num]++;
        }
    }

    for (int i = H - 1; i > 0; i--)
    {
        cnt1[i] += cnt1[i + 1];
        cnt2[i] += cnt2[i + 1];
    }

    int lo = 1, hi = H, minValue = 987654321, minCnt = 0;
    while (lo <= hi)
    {
        int lo_cnt = cnt1[lo] + cnt2[H + 1 - lo];
        int hi_cnt = cnt1[hi] + cnt2[H + 1 - hi];

        if (lo_cnt < minValue)
        {
            minValue = lo_cnt;
            minCnt = 1;
            //cout << lo << " " << lo_cnt << '\n';
        }
        else if (lo_cnt == minValue)
        {
            minCnt++;
            //cout << lo << " " << lo_cnt << '\n';
        }

        if (lo == hi) break;

        if (hi_cnt < minValue)
        {
            minValue = hi_cnt;
            minCnt = 1;
            //cout << hi << " " << hi_cnt << '\n';
        }
        else if (hi_cnt == minValue)
        {
            minCnt++;
            //cout << hi << " " << hi_cnt << '\n';
        }

        lo++; hi--;
    }

    cout << minValue << " " << minCnt;
}