#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int Q = 0, D = 0, N = 0, P = 0;

        int C;
        cin >> C;

        while (C) {
            if (C >= 25) {
                C -= 25;
                Q++;
            }
            else if (C >= 10) {
                C -= 10;
                D++;
            }
            else if (C >= 5) {
                C -= 5;
                N++;
            }
            else {
                C -= 1;
                P++;
            }
        }

        cout << Q << " " << D << " " << N << " " << P << "\n";
    }
}