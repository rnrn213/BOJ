#include <bits/stdc++.h>

using namespace std;

int main() {
    int A, B, C, M;
    cin >> A >> B >> C >> M;

    int t = 0, p = 0, w = 0;
    while (t < 24) {
        if (p + A <= M) {
            w += B;
            p += A;
        }
        else {
            p = (p - C < 0) ? 0 : p - C;
        }

        t++;
    }

    cout << w;
}