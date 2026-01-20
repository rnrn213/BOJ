#include <bits/stdc++.h>

using namespace std;

int N, d[366];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int S, E;
        cin >> S >> E;
        for (int j = S; j <= E; j++)
        {
            d[j]++;
        }
    }

    int i = 1, ans = 0;
    while (i <= 365)
    {
        if (d[i] > 0)
        {
            int j = i, h = d[i];
            while (j <= 365 && d[j] > 0)
            {
                if (h < d[j]) h = d[j];
                j++;
            }
            ans += (j - i) * h;
            i = j;
        }
        else 
        {
            i++;
        }
    }

    cout << ans;
}
