#include <bits/stdc++.h>

using namespace std;

int main() {
    int B, N;

    while (cin >> B >> N) {
        if (B == 0)
            break;

        int A = 1, minDiff = INT_MAX;
        while (abs(B - pow(A, N)) < minDiff) {
            minDiff = abs(B - pow(A, N));
            A++;
        }

        cout << A - 1 << "\n";
    }
}