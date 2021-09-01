#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int ans = 1001;
    for (int start = 1; start <= 1000; start++) {
        int height = start, cnt = 0;
        for (int i = 0; i < N; i++) {
            if (height != A[i]) cnt++;

            height += K;
        }

        if (ans > cnt) ans = cnt;
    }

    cout << ans;
}