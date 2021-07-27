#include <bits/stdc++.h>

using namespace std;

int countZero(int n) {
    if (n == 0) return 1;

    int cnt = 0;
    while (n) {
        if (n % 10 == 0) cnt++;
        n /= 10;
    }
    return cnt;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N, M, cnt = 0;
        cin >> N >> M;
        for (int j = N; j <= M; j++) {
            cnt += countZero(j);
        }
        cout << cnt << "\n";
    }
}