#include <bits/stdc++.h>

using namespace std;

int T, N, cache[191230];

void solve() {
    cache[1] = 1;
    cache[2] = 2;

    for (int i = 3; i <= 191229; i++) {
        cache[i] = (cache[i - 1] + cache[i - 2]) % 1000000007;
    }
}

int main() {

    solve();

    cin >> T;
    for (int i = 0; i < T; i++) {
        scanf("%d", &N);
        printf("%d\n", cache[N]);
    }
}