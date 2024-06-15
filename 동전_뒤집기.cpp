#include <bits/stdc++.h>

using namespace std;

int N;
string c[20];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> c[i];
    }

    int ans = 100000;
    for (int i = 0; i < (1 << N); i++)
    {
        int cnt = 0;
        for (int j = 0; j < N; j++)
        {
            int temp = 0;
            for (int k = 0; k < N; k++)
            {
                if (i & (1 << k))
                {
                    if (c[j][k] == 'H') temp++;
                }
                else
                {
                    if (c[j][k] == 'T') temp++;
                }
            }
            cnt += min(temp, N - temp);
        }
        ans = min(ans, cnt);
    }

    cout << ans;
}