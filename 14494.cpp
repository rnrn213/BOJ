#include <bits/stdc++.h>

using namespace std;

int n, m;

void input() {
    cin >> n >> m;
}

long long solve() {
    vector<long long> D(n, 1), previousD(n, 1);

    for (int i = 1; i < m; i++) {
        D[0] = 1;
        for (int j = 1; j < n; j++) {
            D[j] = (D[j - 1] + previousD[j - 1] + previousD[j]) % 1000000007;
        }
        previousD = D;
    }
    return D[n - 1];
}

int main() {
    input();
    cout << solve();
}