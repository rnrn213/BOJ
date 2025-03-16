#include <bits/stdc++.h>

using namespace std;

int N, cache[1000][1000];
vector<bool> isPrime(1000000, true);

int solve(int l, int r)
{
    if (l == N && r == N) return 0;

    int& ret = cache[l][r];
    if (ret != -1) return ret;
    ret = 0;
    
    int num = stoi(to_string(l) + to_string(r));

    int p = (isPrime[num]) ? 1 : 0;

    if (l < N)
        ret = max(ret, p + solve(l + 1, r));
    if (r < N)
        ret = max(ret, p + solve(l, r + 1));

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    for (int i = 2; i <= sqrt(1000000); i++)
    {
        for (int j = i * i; j < 1000000; j += i)
        {
            isPrime[j] = false;
        }
    }

    cin >> N;

    cout << solve(1, 1) - 1;
}