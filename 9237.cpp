#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int>t(N);
    for (int i = 0; i < N; i++) {
        cin >> t[i];
    }

    sort(t.begin(), t.end(), greater<>());

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, i + 1 + t[i]);
    }

    cout << ans + 1;
}