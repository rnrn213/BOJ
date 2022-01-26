#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
    cin >> N;
    vector<int> peak(N);
    for (int i = 0; i < N; i++) {
        cin >> peak[i];
    }

    int start = 0, ans = 0;
    for (int i = 1; i < N; i++) {
        if (peak[start] < peak[i]) {
            ans = max(ans, i - start - 1);
            start = i;
        }
    }
    ans = max(ans, N - start - 1);

    cout << ans;
}