#include <bits/stdc++.h>

using namespace std;

int N, p[40001], pSize;
vector<int> primes;

void getPrimes()
{
    vector<bool> v(40001, true);
    for (int i = 2; i <= 20000; i++)
    {
        for (int j = i * i; j <= 40000; j += i)
        {
            v[j] = false;
        }
    }

    for (int i = 2; i <= 40000; i++)
    {
        if (v[i]) primes.push_back(i);
    }
    pSize = primes.size();
}

int main()
{
    getPrimes();

    cin >> N;

    p[0] = 1;
    for (int i = 0; i < pSize; i++)
    {
        for (int j = 0; j + primes[i] <= N; j++)
        {
            p[j + primes[i]] = (p[j + primes[i]] + p[j]) % 123456789;
        }
    }

    cout << p[N];
}