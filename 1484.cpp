#include <bits/stdc++.h>

using namespace std;

int G;
vector<int> ans;

void solve() {
    int n = 1;
    while (true) {
        int m = n - 1, tempG = n*n - m*m;
        if (tempG > G) return;

        for (; m > 0; m--) {
            tempG = n*n - m*m;
            if (tempG == G) {
                ans.push_back(n);
                break;
            }
        }
        n++;
    }
}

int main() {
    cin >> G;

    solve();

    if (ans.size() == 0) cout << -1;
    else {
        sort(ans.begin(), ans.end());
        for (auto n: ans) {
            cout << n << "\n";
        }
    }
}