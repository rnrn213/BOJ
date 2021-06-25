#include <bits/stdc++.h>

using namespace std;



int main() {
    int m, Seed, X1, X2;
    cin >> m >> Seed >> X1 >> X2;

    for (int a = 0; a < m; a++) {
        for (int c = 0; c < m; c++) {
            if ((Seed * a + c) % m == X1 && (X1 * a + c) % m == X2) {
                cout << a << " " << c;
                return 0;
            }
        }
    }
}