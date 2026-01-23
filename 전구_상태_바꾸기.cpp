#include <bits/stdc++.h>

using namespace std;

int N, ans = -1;
string s, RGB = "RGB";

int main()
{
    cin >> N >> s;

    for (int i = 0; i < 3; i++)
    {
        int cnt = 0;
        string temp = s;
        for (int j = 0; j < N - 2; j++)
        {
            if (temp[j] == RGB[i]) continue;
            int idx[3];
            for (int k = 0; k < 3; k++)
            {
                for (int m = 0; m < 3; m++)
                {
                    if (temp[j + m] == RGB[k])
                        idx[m] = k;
                }
            }
            int step = (i - idx[0] + 3) % 3;
            cnt += step;
            temp[j] = RGB[(idx[0] + step) % 3];
            temp[j + 1] = RGB[(idx[1] + step) % 3];
            temp[j + 2] = RGB[(idx[2] + step) % 3];
        }

        if (temp[N - 3] == RGB[i] && temp[N - 2] == RGB[i] && temp[N - 1] == RGB[i])
        {
            if (ans == -1) ans = cnt;
            else ans = min(ans, cnt);
        }
    }

    cout << ans;
}