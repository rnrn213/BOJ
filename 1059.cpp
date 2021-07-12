#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> arr, S;
    for (int i = 1; i <= 1000; i++) {
        arr.push_back(i);
    }

    int L, n;
    cin >> L;
    for (int i = 0; i < L; i++) {
        int num;
        cin >> num;
        S.push_back(num);
    }
    cin >> n;

    sort(S.begin(), S.end());

    int min = 1, max = 0, cnt = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == n) {
            min = max = 0;
            break;
        }
        if (S[i] < n) {
            min = S[i] + 1;
        }
        if (S[i] > n && max == 0) {
            max = S[i] - 1;
        }
    }

    for (int i = min; i < max; i++) {
        for (int j = i + 1; j <= max; j++) {
            if (i <= n && n <= j) {
                //cout << "[" << i << ", " << j << "]\n";

                cnt++;
            }
        }
    }
    cout << cnt;
}