#include <bits/stdc++.h>

using namespace std;

int T, n;

long long solve() {
    if (n == 1 || n == 2) return n;
    if (n == 3) return 4;

    long long a = 1, b = 2, c = 4;
    for (int i = 4; i <= n; i++) {
        long long temp = c;
        c = (a + b + c) % 1000000009;
        a = b;
        b = temp;
    }
    return c;
}

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n;
        cout << solve() << '\n';
    }
}