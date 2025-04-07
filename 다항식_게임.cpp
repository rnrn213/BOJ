#include <bits/stdc++.h>

using namespace std;

int T, k, N;
long long cache[21][220];

int main()
{
    cache[1][0] = cache[1][1] = 1;
    int prevMax = 1;
    for (int i = 2; i <= 20; i++)
    {
        for (int j = 0; j <= prevMax; j++)
        {
            for (int m = 0; m <= i; m++)
            {
                cache[i][j + m] += cache[i - 1][j];
            }
        }
        prevMax = prevMax + i;
    }

    cin >> T;
    while (T--)
    {
        cin >> k >> N;

        cout << cache[k][N] << "\n";
    }
}