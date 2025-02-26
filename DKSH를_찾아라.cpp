#include <bits/stdc++.h>

using namespace std;

int N;
long long cache[100001][4];
string s;

int main()
{
    cin >> N >> s;

    long long ans = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cache[i][j] += cache[i - 1][j];
        }

        if (s[i - 1] == 'D')
        {
            cache[i][0] += 1;
        }
        if (s[i - 1] == 'K')
            cache[i][1] += cache[i - 1][0];
        if (s[i - 1] == 'S')
            cache[i][2] += cache[i - 1][1];
        if (s[i - 1] == 'H')
            ans += cache[i - 1][2];

    }

    cout << ans;
}