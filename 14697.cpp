#include <bits/stdc++.h>

using namespace std;

int main() {
    int A, B, C, N, ans = 0;
    cin >> A >> B >> C >> N;

    for (int i = 0; i <= N / A; i++) {
        for (int j = 0; j <= N / B; j++) {
            for (int k = 0; k <= N / C; k++) {
                if (A * i + B * j + C * k == N) ans = 1;
            }
        }
    }
    cout << ans;
}