#include <bits/stdc++.h>

using namespace std;

int diagonal, h, w;

void input() {
    cin >> diagonal >> h >> w;
}

pair<int, int> solve() {
    return make_pair(sqrt(pow(diagonal, 2) / (pow(h, 2) + pow(w, 2))) * h, sqrt(pow(diagonal, 2) / (pow(h, 2) + pow(w, 2))) * w);
}

int main() {
    input();
    pair<int, int> ans = solve();
    cout << ans.first << " " << ans.second;
}