#include <bits/stdc++.h>

using namespace std;

int n, k, coin[100], cnt = 0;

int solve() {
    vector<int> arr(k + 1, 0);
    arr[0] = 1;
    for (int i = 0; i < n; i++) {
        vector<int> temp = arr;
        for (int j = 0; j <= k; j++) {
            if (temp[j] > 0) {
                for (int m = 1; j + coin[i] * m <= k; m++) {
                    arr[j + coin[i] * m] += temp[j];
                }
            }
        }
    }

    return arr[k];
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    sort(coin, coin + n);

    cout << solve();
}