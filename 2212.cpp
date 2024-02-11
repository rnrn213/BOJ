#include <bits/stdc++.h>

using namespace std;

const int INF = 2100000000;

int N, K, sensors[10000];
vector<bool> isVisited(10000, false);

int main()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> sensors[i];
    }

    sort(sensors, sensors + N);

    int ans = 0;
    for (int i = 0; i < N - K; i++)
    {
        int idx = 0, minDist = INF, minIdx = -1;
        while (idx < N)
        {
            if (isVisited[idx])
            {
                idx++;
                continue;
            }

            if (idx + 1 == N) break;

            if (sensors[idx + 1] - sensors[idx] < minDist)
            {
                minDist = sensors[idx + 1] - sensors[idx];
                minIdx = idx;
            }

            idx++;
        }

        ans += minDist;
        isVisited[minIdx] = true;
    }
    
    cout << ans;
}