#include <bits/stdc++.h>

using namespace std;

int solve(long long c) {
    if (c == 0) return 0;

    int degree = 0;
    while (c - pow(7, degree) >= 0) {
        degree++;
    }
    degree--;

    return pow(3, degree) + solve(c - pow(7, degree));
}

int main() {
    long long c;
    cin >> c;

    cout << solve(c);
}