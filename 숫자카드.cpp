#include <bits/stdc++.h>

using namespace std;

int N;
long long cache[41];
string s;

long long solve(int idx)
{
    if (idx >= N) return 1;

    long long& ret = cache[idx];
    if (ret != -1) return ret;
    ret = 0;

    if (idx < N - 1)
    {
        int num = (s[idx] - '0') * 10 + s[idx + 1] - '0';
        if (num >= 10 && num <= 34) ret += solve(idx + 2);
    }
    if (s[idx] != '0')
        ret += solve(idx + 1);

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> s;
    N = s.size();

    cout << solve(0);
}