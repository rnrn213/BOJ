#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        long long S;
        cin >> S;

        if (S % 2 == 0) {
            cout << "NO\n";
            continue;
        }

        string ans = "YES\n";
        for (int j = 3; j < 1000000; j += 2) {
            if (S % j == 0) {
                ans = "NO\n";
                break;
            }
        }

        cout << ans;
    }
}