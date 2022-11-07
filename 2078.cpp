#include <bits/stdc++.h>

using namespace std;

int A, B, L, R;

int main() {
    cin >> A >> B;

    while(A != 1 || B != 1) {
        if (A > B) {
            if (B == 1) {
                L += A - 1;
                A = 1;
            }
            else {
                L += A / B;
                A = A % B;
            }
        }
        else {
            if (A == 1) {
                R += B - 1;
                B = 1;
            }
            else {
                R += B / A;
                B = B % A;
            }
        }
    }

    cout << L << " " << R;
}