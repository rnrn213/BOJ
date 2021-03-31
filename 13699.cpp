#include <bits/stdc++.h>

using namespace std;

long long solve(int n) {
    long long t[36];
    t[0] = 1;
    for (int i = 1; i <= 35; i++) {
        t[i] = 0;
    }
    
    for (int i = 1; i <= 35; i++) {
        for (int j = i - 1; j >= 0; j--) {
            t[i] += t[i - j - 1] * t[j];
        }
    }

    return t[n];
}

int main() {
    int n;
    cin >> n;
    cout << solve(n);
}