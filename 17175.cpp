#include <bits/stdc++.h>

using namespace std;

int n, fibo[51];

void initFibo() {
    memset(fibo, -1, 51 * sizeof(int));
    fibo[0] = fibo[1] = 1;
}

void input() {
    cin >> n;
}

int solve(int num) {
    if (num < 2) return fibo[num];

    int& ret = fibo[num];
    if (ret != -1) return ret;
    ret = 1;
    return ret += (solve(num - 1) + solve(num - 2)) % 1000000007;
}

int main() {
    initFibo();
    input();
    cout << solve(n);
}