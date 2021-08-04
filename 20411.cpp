#include <bits/stdc++.h>

using namespace std;

int main() {
    long long m, Seed, X1, X2;
    cin >> m >> Seed >> X1 >> X2;

    long long a, c;
    for (a = 0; a < m; a++) {
        if ((Seed * a) % m > X1) {
            c = m - ((Seed * a) % m) + X1;
        }
        else {
            c = X1 - ((Seed * a) % m);
        }

        if (c < m && (X1 * a + c) % m == X2) {
            cout << a << " " << c;
            break;
        }
    }
}