#include <bits/stdc++.h>

using namespace std;

int N, line[201], cache[201];

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> line[i];
    }

    int a = 0;
    for (int i = 1; i <= N; i++)
    {
        cache[i] = 1;
        for (int j = i - 1; j > 0; j--)
        {
            if (line[j] < line[i])
            {
                cache[i] = max(cache[i], 1 + cache[j]);
            }
        }
        if (cache[i] > a) a = cache[i];
    }

    cout << N - a;
}