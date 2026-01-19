#include <bits/stdc++.h>

using namespace std;

int N, M, t[16];

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int num, k = -1;
        cin >> num;
        while (num)
        {
            num /= 2;
            k++;
        }
        t[k]++;
    }

    int ans = 0;
    for (int i = 15; i >= 0;)
    {
        if (t[i] > 0)
        {
            t[i]--;
            ans += pow(2, i);
            int j = M - 1, idx = i;
            while (j > 0 && idx >= 0)
            {
                while (j > 0 && t[idx] > 0)
                {
                    j--;
                    t[idx]--;
                }
                j *= 2;
                idx--;
            }
        }
        i = -1;
        for (int j = 15; j >= 0; j--)
        {
            if (t[j] > 0)
            {
                i = j;
                break;
            }
        }
    }
    cout << ans;
}
