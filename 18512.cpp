#include <bits/stdc++.h>

using namespace std;

int main() {
    int X, Y, P1, P2;
    cin >> X >> Y >> P1 >> P2;
    
    int A[2], B[2];
    if (X >= Y) {
        A[0] = P1, A[1] = X;
        B[0] = P2, B[1] = Y;
    }
    else {
        A[0] = P2, A[1] = Y;
        B[0] = P1, B[1] = X;
    }
    int ans = -1;
    for (int i = 0; i <= 100; i++) {
        while (A[0] > B[0]) {
            B[0] += B[1];
        }
        if (A[0] == B[0]) {
            ans = A[0];
            break;
        }
        A[0] += A[1];
    }
    cout << ans;
}