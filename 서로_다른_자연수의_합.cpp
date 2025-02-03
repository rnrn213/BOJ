#include <bits/stdc++.h>    

using namespace std;

const int X = 100999;

int T, N, cache[2001][2001];

int solve(int num, int idx)
{
    if (num == 0) return 1;

    int& ret = cache[num][idx];
    if (ret != -1) return ret;
    ret = 0;

    for (int i = idx; i <= num; i++)
    {
        ret = (ret + solve(num - i, i + 1)) % X;
    }

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));
    
    cin >> T;
    while (T--)
    {
        cin >> N;

        cout << solve(N, 1) << "\n";
    }
}