#include <bits/stdc++.h>

using namespace std;

int n;

void input() {
    cin >> n;
}

int solve() {
    vector<int> v = {0, 1};
    for (int i = 2; i <= n; i++) {
        v.push_back((v[i - 1] + v[i - 2]) % 1000000007);
    }

    return v[n];
}

int main() {
    input();
    cout << solve();
}