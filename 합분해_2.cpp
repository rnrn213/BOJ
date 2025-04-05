#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000000;

int N, K, cache[5001][5001];

int main()
{
    cin >> N >> K;

    cache[0][0] = 1;
    for (int i = 1; i <= K; i++)
    {   
        int sum = 0;
        for (int j = 0; j <= N; j++)
        {
            sum = (sum + cache[i - 1][j]) % MOD;
            cache[i][j] = sum;
        }
    }

    cout << cache[K][N];
}