#include <bits/stdc++.h>

using namespace std;

int N, coins[100001];

void initCoins() {
    memset(coins, -1, 100001 * sizeof(int));
}

void input() {
    cin >> N;
}

int solve(int num) {
    if (num == 0) return 0;
    if (num < 1) return 1000000000;

    int& ret = coins[num];
    if (ret != -1) return ret;
    ret = 1;
    return ret = min({ret + solve(num - 7), ret + solve(num - 5), ret + solve(num - 2), ret + solve(num - 1)});
}

int main() {
    initCoins();
    input();
    cout << solve(N);
}