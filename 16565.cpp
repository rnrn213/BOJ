#include <bits/stdc++.h>

using namespace std;

int N;

long long C(int n, int m) {
    long long ret = 1;

    int j = 1;
    for (int i = m + 1; i <= n; i++) {
        ret *= i;
        if (ret % j == 0 && j <= n - m) {
            ret /= j;
            j++;
        }
    }
    for (int i = j; i <= n - m; i++) {
        ret /= i;
    }

    return ret;
}

int main() {
    cin >> N;

    long long cnt[14];
    for (int i = 1; i <= 13; i++) {
        cnt[i] = C(13, i);
    }

    if (N < 4) {
        cout << 0;
        return 0;
    }
    else {
        for (int i = 1; i <= N / 4; i++) {
            cnt[i] = (cnt[i] * C(52 - 4 * i, N - 4 * i)) % 10007;
        }

        long long ans = 0;
        for (int i = 1; i <= N / 4; i++) {
            ans += (((int)pow(-1, i + 1) * cnt[i]) + 10007) % 10007;
        }
        cout << ans % 10007;
    }
}