#include <bits/stdc++.h>

using namespace std;

int N;

double cache[1000001];

double solve(int num)
{
    if (num <= 0) return 0.0;

    double& ret = cache[num];
    if (ret >= 0.0 - 1e-6) return ret;
    ret = 0.0;

    for (int i = 1; i <= 6; i++)
    {
        ret += (1 + solve(num - i)) / 6.0;
    }

    return ret;
}


int main()
{
    cin >> N;

    for (int i = 0; i <= N; i++)
    {
        cache[i] = -1.0;
    }

    cout << fixed;
    cout.precision(12);
    cout << solve(N);
}