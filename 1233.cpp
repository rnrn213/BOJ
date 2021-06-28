#include <bits/stdc++.h>

using namespace std;



int main() {
    int S1, S2, S3;
    cin >> S1 >> S2 >> S3;

    vector<int> count(S1 + S2 + S3 + 1, 0);
    for (int i = 1; i <= S1; i++) {
        for (int j = 1; j <= S2; j++) {
            for (int k = 1; k <= S3; k++) {
                count[i + j + k]++;
            }
        }
    }

    int ans = 0, maxValue = -1;
    for (int i = 1; i < count.size(); i++) {
        if (count[i] > maxValue) {
            maxValue = count[i];
            ans = i;
        }
    }
    cout << ans;
}