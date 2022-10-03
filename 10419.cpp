#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int d;
        cin >> d;

        int a = 0;
        while (a + pow(a, 2) <= d) {
            a++;
        }

        cout << a - 1 << "\n";
    }
}