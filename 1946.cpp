#include <bits/stdc++.h>

using namespace std;

int T, N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int tc = 0; tc < T; tc++)
    {
        cin >> N;

        pair<int, int> score[100000];
        for (int i = 0; i < N; i++)
        {
            cin >> score[i].first >> score[i].second;
        }

        sort(score, score + N);

        int m = score[0].second, ans = 0;
        for (int i = 0; i < N; i++)
        {
            if (score[i].second <= m)
            {
                ans++;
                m = score[i].second;
            }
        }

        cout << ans << '\n';
    }
}