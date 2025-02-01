#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll hLen[51], p[51], X;
int N;

ll solve(int idx, ll length)
{
    if (idx == 0)
    {
        if (length > 0) return 1;
        else return 0;
    }
    if (length <= 1) return 0;
    if (length >= hLen[idx]) return p[idx];

    ll ret = (length >= 2 + hLen[idx - 1]) ? 1 : 0;
    ret += solve(idx - 1, length - 1) + solve(idx - 1, length - hLen[idx - 1] - 2);

    return ret;
}

int main()
{

    hLen[0] = 1;
    p[0] = 1;
    for (int i = 1; i <= 50; i++)
    {
        hLen[i] = 3 + 2 * hLen[i - 1];
        p[i] = 1 + 2 * p[i - 1];
    }

    cin >> N >> X;

    cout << solve(N, X);
}