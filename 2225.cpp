#include <bits/stdc++.h>

using namespace std;

int N, K, cache[201][201];

int solve(int n, int k) {
    if (n == 0 && k == 0)
        return 1;
    else if (k == 0)
        return 0;
    
    int& ret = cache[n][k];
    if (ret != -1)
        return ret;
    ret = 0;

    for (int i = 0; i <= n; i++) {
        ret = (ret + solve(n - i, k - 1)) % 1000000000;
    }

    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));

    cin >> N >> K;

    cout << solve(N, K);
}