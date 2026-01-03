#include <bits/stdc++.h>

using namespace std;


string s;
int cache[3001][2], sSize;

int solve(int idx, int c)
{
    if (idx == sSize) return 0;

    int& ret = cache[idx][c];
    if (ret != -1) return ret;

    int idxCase = (s[idx] - 'a' < 0) ? 1 : 0;
    if (idxCase == c) ret = 1 + solve(idx + 1, c);
    else ret = 2 + min(solve(idx + 1, c), solve(idx + 1, !c));

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> s;
    sSize = s.size();
    
    cout << solve(0, 0);
}
