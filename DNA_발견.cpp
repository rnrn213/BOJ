#include <bits/stdc++.h>

using namespace std;

int N, cache[1000000][2];
string dna;

int solve(int idx, int ab)
{
    if (idx == N)
        return (ab == 0) ? 0 : 1;
    
    int& ret = cache[idx][ab];
    if (ret != -1) return ret;
    ret = 2100000000;

    if (ab == 0)
    {
        if (dna[idx] == 'A')
        {
            ret = min({ret, solve(idx + 1, ab), 1 + solve(idx + 1, !ab)});
        }
        if (dna[idx] == 'B')
        {
            ret = min(ret, 1 + solve(idx + 1, ab));
        }
    }
    if (ab == 1)
    {
        if (dna[idx] == 'A')
        {
            ret = min(ret, 1 + solve(idx + 1, ab));
        }
        if (dna[idx] == 'B')
        {
            ret = min({ret, solve(idx + 1, ab), 1 + solve(idx + 1, !ab)});
        }
    }

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N >> dna;

    cout << min(solve(0, 0), solve(0, 1));
}