#include <bits/stdc++.h>

using namespace std;

vector<int> T = {-1};

int isValid(int k) {
    for (int i = 1; T[i] < k; i++) {
        for (int j = i; T[j] < k; j++) {
            for (int m = i; T[m] < k; m++) {
                if (T[i] + T[j] + T[m] == k) return 1;
            }
        }
    }
    return 0;
}

int main() {
    for (int i = 1; *(T.end() - 1) < 1000; i++) {
        T.push_back((i * (i + 1)) / 2);
    }

    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        cout << isValid(k) << "\n";
    }
}