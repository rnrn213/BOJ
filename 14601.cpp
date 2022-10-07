#include <bits/stdc++.h>

using namespace std;

int M[129][129], n = 0;

bool isDrain(int y, int x, int size) {
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (M[i][j] != 0)
                return true;
        }
    }

    return false;
}

void solve(int y, int x, int size) {
    n++;
    int halfSize = size / 2;
    if (!isDrain(y, x, halfSize))
        M[y + halfSize - 1][x + halfSize - 1] = n;
    if (!isDrain(y, x + halfSize, halfSize))
        M[y + halfSize - 1][x + halfSize] = n;
    if (!isDrain(y + halfSize, x, halfSize))
        M[y + halfSize][x + halfSize - 1] = n;
    if (!isDrain(y + halfSize, x + halfSize, halfSize))
        M[y + halfSize][x + halfSize] = n;
    
    if (size == 2)
        return;
    
    solve(y, x, halfSize);
    solve(y, x + halfSize, halfSize);
    solve(y + halfSize, x, halfSize);
    solve(y + halfSize, x + halfSize, halfSize);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int K, x, y;
    cin >> K >> x >> y;

    M[y][x] = -1;

    solve(1, 1, pow(2, K));

    for (int i = pow(2, K); i > 0; i--) {
        for (int j = 1; j <= pow(2, K); j++) {
            cout << M[i][j] << " ";
        }
        cout << "\n";
    }
}