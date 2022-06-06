#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> coins(N);
    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }

    int minCoins = 0;
    while (K > 0) {
        int i = N - 1;
        while (coins[i] > K) {
            i--;
        }

        minCoins += K / coins[i];
        K = K % coins[i];
    }

    cout << minCoins;
}