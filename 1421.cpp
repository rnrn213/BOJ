#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, C, W, maxLength = 0;
    cin >> N >> C >> W;
    vector<int> woods(N);
    for (int i = 0; i < N; i++) {
        cin >> woods[i];
        if (woods[i] > maxLength)
            maxLength = woods[i];
    }

    long long maxMoney = 0;
    for (int L = 1; L <= maxLength; L++) {
        long long money = 0;
        for (int i = 0; i < N; i++) {
            int K = woods[i] / L, cutCount = (woods[i] % L == 0) ? woods[i] / L - 1 : woods[i] / L, 
                ithWoodPrice = K * W * L - cutCount * C;
            
            if (ithWoodPrice > 0)
                money += ithWoodPrice;
        }

        if (money > maxMoney)
            maxMoney = money;
    }

    cout << maxMoney;
}