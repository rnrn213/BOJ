#include <bits/stdc++.h>

using namespace std;

const int MAX = 1 << 15;

int N, cache[(1 << 15) + 1][5];

int main()
{
    cache[0][0] = 1;
    int i = 1;
    while (i * i <= MAX)
    {
        for (int j = 0; j + i * i <= MAX; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                cache[j + i * i][k + 1] += cache[j][k];
            }
        }

        i++;
    }

    while (true)
    {
        cin >> N;
        if (N == 0) break;

        cout << cache[N][1] + cache[N][2] + cache[N][3] + cache[N][4] << "\n";
    }
}