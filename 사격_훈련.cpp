#include <bits/stdc++.h>

using namespace std;

int N;
double P, Q, cache[21][30];

double cal(int idx, int hit)
{
    if (hit < 0 || idx < hit) return 0.000000000000;
    if (idx == 0) return 1.00000000000000;

    return Q * cal(idx - 1, hit - 1) + (1 - Q) * cal(idx - 1, hit);
}

int main()
{
    cin >> N >> P >> Q;
    double ans = 0.0;
    for (int i = 0; i <= N; i++)
    {
        cache[0][i] = cal(N, i);
        ans += i * cache[0][i];
    }

    for (int i = 1; i <= N; i++)
    {   
        double v = 0.0000000000000000000;
        for (int j = 0; j <= N; j++)
        {
            if (j > 0) cache[i][j] += P * cache[i - 1][j - 1];
            cache[i][j] += (1 - P) * cache[i - 1][j];

            v += j * cache[i][j];
        }

        if (ans < v) ans = v;
    }

    cout << fixed;
    cout.precision(11);
    cout << ans;
}