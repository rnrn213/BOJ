#include <bits/stdc++.h>

using namespace std;

int N, h[51];

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> h[i];
    }

    int maxCnt = 0;
    for (int i = 1; i <= N; i++)
    {
        int cnt = 0;
        for (int j = 1; j < i; j++)
        {
            double x = (double)(h[i] - h[j]) / (i - j);
            bool isValid = true;
            for (int k = j + 1; k < i; k++)
            {
                if ((double)h[k] - (h[j] + x * (k - j)) > -1 * 1e-6)
                {
                    isValid = false;
                    break;
                }
            }

            if (isValid) cnt++;
        }
        for (int j = i + 1; j <= N; j++)
        {
            double x = (double)(h[j] - h[i]) / (j - i);
            bool isValid = true;
            for (int k = i + 1; k < j; k++)
            {
                if ((double)h[k] - (h[i] + x * (k - i)) > -1 * 1e-6)
                {
                    isValid = false;
                    break;
                }
            }

            if (isValid) cnt++;
        }

        if (cnt > maxCnt) maxCnt = cnt;
    }

    cout << maxCnt;
}