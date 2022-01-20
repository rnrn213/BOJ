#include <bits/stdc++.h>

using namespace std;


int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int T, P, Q;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> P >> Q;

        long long a = 0, b = 1 % Q, c = 1 % Q;
        for (int j = 2; j <= P; j++) {
            c = (a + b) % Q;
            a = b % Q;
            b = c % Q;
        }
        cout << "Case #" << i + 1 << ": " << c << "\n";
    }
}