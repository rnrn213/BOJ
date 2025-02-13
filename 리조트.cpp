#include <bits/stdc++.h>

using namespace std;

int N, M, cache[101][41];
vector<bool> days(101, true);

int solve(int idx, int c)
{
    if (idx > N) return 0;

    int& ret = cache[idx][c];
    if (ret != -1) return ret;
    ret = 2100000000;

    if (days[idx] == false)
        return ret = solve(idx + 1, c);
    
    ret = min(ret, 10000 + solve(idx + 1, c));
    ret = min(ret, 25000 + solve(idx + 3, c + 1));
    ret = min(ret, 37000 + solve(idx + 5, c + 2));
    if (c >= 3)
        ret = min(ret, solve(idx + 1, c - 3));

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int num;
        cin >> num;
        days[num] = false;
    }

    cout << solve(1, 0);
}