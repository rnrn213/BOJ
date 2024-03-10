#include <bits/stdc++.h>

using namespace std;

int N, cache[100], cacheB[100];
vector< pair<int, int> > EL(100);

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> EL[i].first >> EL[i].second;
    }

    sort(EL.begin(), EL.begin() + N);

    int maxLIS = 0;
    for (int i = 0; i < N; i++)
    {
        cache[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (EL[i].second > EL[j].second) cache[i] = max(cache[i], 1 + cache[j]);
        }

        maxLIS = max(maxLIS, cache[i]);
    }

    cout << N - maxLIS;
}