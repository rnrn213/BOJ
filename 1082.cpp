#include <bits/stdc++.h>

using namespace std;

int N, P[10], M, minPIdx = 0;
string ans = "";

void solve() {
    int k = M / P[minPIdx];
    for (int i = 0; i < k; i++) {
        ans += (char)('0' + minPIdx);
    }
    M = M % P[minPIdx];

    bool isZero = (minPIdx == 0) ? true : false;
    for (int i = ans.size() - 1; i >= 0; i--) {
        for (int j = N - 1; j > minPIdx; j--) {
            if (M + P[ans[i] - '0'] >= P[j]) {
                M = M + P[ans[i] - '0'] - P[j];
                ans[i] = (char)('0' + j);
                if (isZero)
                    isZero = false;
                break;
            }
        }

        if (isZero)
            M += P[0];
    }

    while (ans.size() > 1 && *(ans.end() - 1) == '0')
        ans.pop_back();

    return;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        if (P[i] <= P[minPIdx])
            minPIdx = i;
    }
    cin >> M;

    solve();
    reverse(ans.begin(), ans.end());

    cout << ans;
}