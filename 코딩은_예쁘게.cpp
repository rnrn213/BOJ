#include <bits/stdc++.h>

using namespace std;

int N, tab[1001], ans[1001];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> tab[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> ans[i];
    }

    int cnt = 0;
    while (true)
    {
        priority_queue< pair<int, pair<int, pair<int, int> > > > pq;
        int i = 0;
        bool isFinished = true;
        while (i < N)
        {
            if (tab[i] > ans[i])
            {
                isFinished = false;
                int start = i, minGap = -1000;
                while (i < N && tab[i] > ans[i])
                {
                    if (ans[i] - tab[i] > minGap) minGap = ans[i] - tab[i];
                    i++;
                }
                int end = i;
                pq.push(make_pair(end - start + 1, make_pair(minGap, make_pair(start, end))));
            }
            else if (tab[i] < ans[i])
            {
                isFinished = false;
                int start = i, minGap = 1000;
                while (i < N && tab[i] < ans[i])
                {
                    if (ans[i] - tab[i] < minGap) minGap = ans[i] - tab[i];
                    i++;
                }
                int end = i;
                pq.push(make_pair(end - start + 1, make_pair(minGap, make_pair(start, end))));
            }
            else
            {
                i++;
            }
        }
        if (isFinished) break;

        pair<int, pair<int, pair<int, int> > > pp = pq.top();
        for (int j = pp.second.second.first; j < pp.second.second.second; j++)
        {
            tab[j] += pp.second.first;
        }
        cnt += abs(pp.second.first);
    }

    cout << cnt;
}