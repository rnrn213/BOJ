#include <bits/stdc++.h>

using namespace std;

int a, b, c;

void input() {
    cin >> a >> b >> c;
}

int solve() {
    if (a == b && b == c) return 10000 + a * 1000;
    if (a == b || a == c) return 1000 + a * 100;
    if (b == c) return 1000 + b * 100;

    if (a >= b && a >= c) return a * 100;
    if (b >= a && b >= c) return b * 100;
    return c * 100;
}

int main() {
    input();
    cout << solve();
}