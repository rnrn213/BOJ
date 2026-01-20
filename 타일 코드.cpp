#include <bits/stdc++.h>

using namespace std;

int N, cache[31][31];

int temp[31];

int solve1()
{
    temp[1] = 1;
    temp[2] = 3;
    for (int i = 3; i <= N; i++)
    {
        temp[i] = temp[i - 1] + 2 * temp[i - 2];
    }

    return temp[N];
}

int solve(int l, int r)
{
    if (l == r || l > r) return 1;
    if (r - l == 1) return 3;

    int& ret = cache[l][r];
    if (ret != -1) return ret;
    ret = solve(l + 1, r - 1);
    
    if (r - l >= 3)
        ret += 2 * solve(l + 2, r - 2);

    return ret;
}

int main () 
{
    memset(cache, -1, sizeof(cache));

    cin >> N;
    cout << solve(0, N - 1) + (solve1() - solve(0, N - 1)) / 2;
}
