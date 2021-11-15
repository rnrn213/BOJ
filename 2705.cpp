#include <bits/stdc++.h>

using namespace std;

int cache[1001];

int main() {
    cache[0] = cache[1] = 1;
    for (int i = 2; i <= 1000; i++) {
        for (int j = 0; j <= i; j++) {
            if ((i - j) % 2 == 0) {
                cache[i] += cache[(i - j) / 2];
            }
        }
    }

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        cout << cache[n] << "\n";
    }

}