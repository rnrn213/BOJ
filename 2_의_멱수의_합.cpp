#include <bits/stdc++.h>

using namespace std;

int N, cache[1000001];

int main()
{
    cache[0] = 1;
    for (int i = 1; i <= 1000000; i *= 2)
    {
        for (int j = 0; j <= 1000000; j++)
        {
            if (j + i > 1000000) break;

            cache[j + i] = (cache[j + i] + cache[j]) % 1000000000;
        }
    }

    cin >> N;

    cout << cache[N];
}