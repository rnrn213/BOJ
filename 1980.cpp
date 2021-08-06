#include <bits/stdc++.h>

using namespace std;

pair<int, int> solve(int n, int m, int t) {
    if (n < m) return solve(m, n, t);

    pair<int, int> ret = make_pair(0, t);

    for (int i = 0; i <= t / n; i++) {
        int remainT = t - n * i;
        if (remainT % m < ret.second) {
            ret = make_pair(i + remainT / m, remainT % m);
        }
        if (remainT % m == ret.second && i + remainT / m > ret.first) {
            ret.first = i + remainT / m;
        }
    }

    return ret;
}

int main() {
    int n, m, t;
    cin >> n >> m >> t;

    pair<int, int> ans = solve(n, m, t);
    cout << ans.first << " " << ans.second;
}