#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    sort(P.begin(), P.end());

    int ans = 0, iTime = 0;
    for (int i = 0; i < N; i++) {
        iTime += P[i];
        ans += iTime;
    }

    cout << ans;
}