#include <bits/stdc++.h>

using namespace std;

int BCD[3], sales;

int main() {
    cin >> BCD[0] >> BCD[1] >> BCD[2];
    sales = min({BCD[0], BCD[1], BCD[2]});

    int beforeSale = 0, afterSale = 0;
    for (int i = 0; i < 3; i++) {
        vector<int> cost(BCD[i]);
        for (int j = 0; j < BCD[i]; j++) {
            cin >> cost[j];
            beforeSale += cost[j];
        }
        sort(cost.begin(), cost.end(), greater<>());
        for (int j = 0; j < BCD[i]; j++) {
            if (j < sales) {
                afterSale += (cost[j] / 10) * 9;
            }
            else {
                afterSale += cost[j];
            }
        }
    }

    cout << beforeSale << "\n" << afterSale;
}