#include <bits/stdc++.h>

using namespace std;

int T, n, k, dp[188][1121][15];
vector<int> primes;

bool isPrime(int num)
{
    if (num == 1 || num == 0) return false;

    for (int i = 2; i <= (num + 1) / 2; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int solve(int idx, int num, int cnt)
{
    if (cnt == 0)
    {
        if (num == 0) return 1;
        else return 0;
    }
    if (idx == primes.size()) return 0;
    if (num < 0) return 0;

    int& ret = dp[idx][num][cnt];
    if (ret != -1) return ret;
    ret = 0;

    return ret = solve(idx + 1, num, cnt) + solve(idx + 1, num - primes[idx], cnt - 1);
}

int main()
{
    memset(dp, -1, sizeof(dp));

    for (int i = 2; i <= 1120; i++)
    {
        if (isPrime(i)) primes.push_back(i);
    }

    cin >> T;
    for (int tc = 0; tc < T; tc++)
    {
        cin >> n >> k;

        cout << solve(0, n, k) << "\n";
    }
}