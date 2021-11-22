#include <bits/stdc++.h>

using namespace std;

int main() {
    int A, B, C;
    while (cin >> A >> B >> C) {
        int cnt = 0;
        while (B - A != 1 || C - B != 1) {
            if (B - A > C - B) {
                int temp = B;
                B = A + 1;
                C = temp;
                cnt++;
            }
            else {
                int temp = B;
                B = C - 1;
                A = temp;
                cnt++;
            }
        }

        cout << cnt << "\n";
    }
}