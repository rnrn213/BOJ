#include <bits/stdc++.h>

using namespace std;

int countPair(int n, int m) {
    int count = 0, a = 1, b = 2;
    while (b < n) {
        if ((static_cast<int>(pow(a, 2)) + static_cast<int>(pow(b, 2)) + m) % (a * b) == 0) {
            count++;
        }
        b++;
        if (b == n) {
            a++;
            b = a + 1;
        }
    }
    return count;
}

int main() {
    int T, n, m;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n >> m;
        cout << countPair(n, m) << '\n';
    }
}