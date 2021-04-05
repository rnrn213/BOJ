#include <bits/stdc++.h>

using namespace std;

int N;

void input() {
    cin >> N;
}

long long solve() {
    if (N <= 2) return 1;

    long long pN[2] = {1, 1};
    for (int i = 3; i <= N; i++) {
        long long temp = pN[0] + pN[1];
        pN[0] = pN[1];
        pN[1] = temp;
    }
    return pN[1];
}

int main() {
    input();
    cout << solve();
}