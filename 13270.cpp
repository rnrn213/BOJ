#include <bits/stdc++.h>

using namespace std;

int fibo[5000], cache[5000][2];

int solve(int n, int j) {
    if (n == 0)
        return 0;
    
    int& ret = cache[n][j];
    if (ret != -1)
        return ret;
    ret = (j == 0) ? 1000000000 : 0;
    int i = 2;
    while (fibo[i] <= n) {
        ret = (j == 0) ? min(ret, fibo[i - 1] + solve(n - fibo[i], j)) : max(ret, fibo[i - 1] + solve(n - fibo[i], j));

        i++;
    }

    return ret;
}

int main() {
    fibo[0] = fibo[1] = 1;
    for (int i = 2; i < 5000; i++)
        fibo[i] = fibo[i - 2] + fibo[i - 1];
    
    memset(cache, -1, 5000 * 2 * sizeof(int));

    int N;
    cin >> N;

    solve(N, 0);
    solve(N, 1);

    cout << cache[N][0] << " " << cache[N][1];
}