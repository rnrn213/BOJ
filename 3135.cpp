#include <bits/stdc++.h>

using namespace std;

int main() {
    int A, B, N;
    cin >> A >> B >> N;

    int ans = abs(A - B);
    for (int i = 0; i < N; i++) {
        int f;
        cin >> f;
        ans = (ans > 1 + abs(f - B)) ? 1 + abs(f - B) : ans;
    }

    cout << ans;
}