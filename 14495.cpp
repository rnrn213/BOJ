#include <bits/stdc++.h>

using namespace std;

int n;

void input() {
    cin >> n;
}

long long solve() {
    vector<long long> v = {-1, 1, 1, 1};
    for (int i = 4; i <= n; i++) {
        v.push_back(v[i - 1] + v[i - 3]);
    }

    return v[n];
}

int main() {
    input();
    cout << solve();
}