#include <bits/stdc++.h>

using namespace std;

int N, C[51], M, B[51];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> C[i];
    }
    sort(C, C + N + 1, greater<>());

    cin >> M;
    int cnt = 0;
    for (int i = 0; i < M; i++)
    {
        int w;
        cin >> w;
        for (int j = 0; j < N; j++)
        {
            if (C[j] >= w && w > C[j + 1]) 
            {
                B[j]++;
                cnt++;
                break;
            }
        }
    }

    if (cnt != M) cout << -1;
    else 
    {
        int ans = 0;
        while (M > 0)
        {
            int cnt = 0;
            for (int i = 0; i < N; i++)
            {
                cnt++;
                for (int j = i; j < N; j++)
                {
                    while (B[j] && cnt > 0)
                    {
                        B[j]--;
                        cnt--;
                        M--;
                    }
                    if (cnt == 0) break;
                }
            }

            ans++;
        }

        cout << ans;
    }
}