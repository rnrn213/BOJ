#include <bits/stdc++.h>

using namespace std;

const int DIV = 1000000;

string S;
int cache[5001], sSize;

int solve(int idx)
{
    if (idx >= sSize) return 1;

    int& ret = cache[idx];
    if (ret != -1) return ret;
    ret = 0;

    int n = S[idx] - '0';
    int m = (idx + 1 < sSize) ? S[idx + 1] - '0' : -1;

    if (n > 0)
        ret = (ret + solve(idx + 1)) % DIV;
    if ((n == 1 && (m >= 0 && m <= 9)) || (n == 2 && (m >= 0 && m <= 6)))
        ret = (ret + solve(idx + 2)) % DIV;

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> S;
    sSize = S.size();

    cout << solve(0);
}