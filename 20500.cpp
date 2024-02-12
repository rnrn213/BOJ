#include <bits/stdc++.h>

using namespace std;

int N, cache[1516][15];

int solve(int idx, int num)
{
    if (idx == 1)
    {
        if ((num * 10 + 5) % 15 == 0) return 1;
        else return 0;
    }

    int &ret = cache[idx][num];
    if (ret != -1) return ret;
    ret = 0;

    return ret = (solve(idx - 1, (num * 10 + 1) % 15) % 1000000007
                    + solve (idx - 1, (num * 10 + 5) % 15) % 1000000007) % 1000000007;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N;

    cout << solve(N, 0);
}