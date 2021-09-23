#include <bits/stdc++.h>

using namespace std;

int main() {
    int one, n;
    char slash;

    while (cin >> one >> slash >> n) {
        int cnt = 0;
        for (int x = n + 1;; x++) {
            if ((x * n) % (x - n) == 0)
                cnt++;
            if (x == (x * n) / (x - n))
                break;
        }
        cout << cnt << "\n";
    }
}