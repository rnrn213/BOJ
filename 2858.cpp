#include <bits/stdc++.h>

using namespace std;

int main() {
    int R, B;
    cin >> R >> B;

    int L = 1, W = 1;

    while (true) {
        if (L * W == R + B) break;

        L++;
        if (L + W > (R + 4) / 2) {
            W++;
            L = W;
        }
    }
    cout << L << " " << W;
}