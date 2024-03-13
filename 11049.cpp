#include <bits/stdc++.h>

using namespace std;

int N, cache[500][500];
vector< pair<int, int> > v(500);

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    for (int k = 1; k < N; k++)
    {
        for (int i = 0; i < N - k; i++)
        {
            cache[i][i + k] = INT_MAX;
            for (int j = 0; j < k; j++)
            {
                cache[i][i + k] = min(cache[i][i + k], cache[i][i + j] + cache[i + j + 1][i + k] + v[i].first * v[i + j].second * v[i + k].second);
            }
        }
    }

    cout << cache[0][N - 1];
}