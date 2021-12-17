#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    string seat;
    cin >> seat;
    int cupHolderSize = 1;
    for (int i = 0; i < N; i++) {
        if (seat[i] == 'L')
            i++;
        cupHolderSize++;
    }

    vector<bool> isValidCupHolder(cupHolderSize, true);

    int j = 0, ans = 0;
    for (int i = 0; i < N; i++) {
        if (seat[i] == 'S') {
            if (isValidCupHolder[j]) {
                ans++;
                isValidCupHolder[j] = false;
            }
            else {
                ans++;
                isValidCupHolder[j + 1] = false;
            }
        }
        if (seat[i] == 'L') {
            if (isValidCupHolder[j]) {
                ans++;
                isValidCupHolder[j] = false;
            }
            if (isValidCupHolder[j + 1]) {
                ans++;
                isValidCupHolder[j + 1] = false;
            }
            i++;
        }
        j++;
    }

    cout << ans;
}