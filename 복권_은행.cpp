#include <bits/stdc++.h>

using namespace std;

int N, J, C, m[51], sum = 0;
double cache[1001][1001];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> m[i];
        sum += m[i];
    }
    cin >> J >> C;

    cache[0][0] = 1.0;
    for (int i = 1; i <= C; i++)
    {
        cache[i][0] = cache[i - 1][0] * (sum + J * (i - 1) - m[0]) / (sum + J * (i - 1));
        for (int k = 1; k < i; k++)
        {
            cache[i][k] = (cache[i - 1][k - 1] * (m[0] + J * (k - 1)) / (sum + J * (i - 1))) + (cache[i - 1][k] * (sum + J * (i - 1) - (m[0] + J * k)) / (sum + J * (i - 1)));
        }
        cache[i][i] = cache[i - 1][i - 1] * (m[0] + J * (i - 1)) / (sum + J * (i - 1));
    }

    double ans = 0.0;
    for (int i = 0; i <= C; i++)
    {
        ans += (m[0] + J * i) * cache[C][i];
    }

    cout << fixed;
    cout.precision(9);
    cout << ans;
}