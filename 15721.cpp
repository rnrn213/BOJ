#include <bits/stdc++.h>

using namespace std;

int solve(int A, int T, int flag) {
    int n = 1, p = -1, count[2] = {0, 0};

    while (true) {
        for (int i = 0; i < 4; i++) {
            if (i % 2 == 0) count[0]++;
            else count[1]++;
            p = (p + 1) % A;
            if (count[flag] == T) return p;
        }
        for (int i = 0; i <= n; i++) {
            count[0]++;
            p = (p + 1) % A;
            if (count[flag] == T) return p;
        }
        for (int i = 0; i <= n; i++) {
            count[1]++;
            p = (p + 1) % A;
            if (count[flag] == T) return p;
        }
        n++;
    }
    return -1;
}

int main() {
    int A, T, flag;
    cin >> A >> T >> flag;

    cout << solve(A, T, flag);
}