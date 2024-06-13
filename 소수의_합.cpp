#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int T;
vector<bool> isPrime(100001, true);
vector<int> p, v(100001, 0);

int main()
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= 100000; i++)
    {
        if (!isPrime[i]) continue;

        p.push_back(i);

        for (int j = i+i; j <= 100000; j += i)
        {
            isPrime[j] = false;
        }
    }

    for (int i = 0; i < p.size(); i++)
    {
        v[p[i]] = (v[p[i]] + 1) % MOD;
        for (int j = 0; j + p[i] <= 100000; j++)
        {
            if (v[j] > 0)
            {
                v[j + p[i]] = (v[j + p[i]] + v[j]) % MOD;
            }
        }
    }

    cin >> T;
    for (int tc = 0; tc < T; tc++)
    {
        int n;
        cin >> n;
        cout << v[n] << "\n";
    }
}