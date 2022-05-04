#include <bits/stdc++.h>

using namespace std;

int main() {
    string msg = "mixed";
    int n;
    cin >> n;
    if (n == 1) {
        bool isAscending = true;
        for (int i = 0; i < 7; i++) {
            int m;
            cin >> m;
            if (m - n != 1) {
                isAscending = false;
                break;
            }
            n = m;
        }

        if (isAscending) {
            msg = "ascending";
        }
    }
    else if (n == 8) {
        bool isDescending = true;
        for (int i = 0; i < 7; i++) {
            int m;
            cin >> m;
            if (n - m != 1) {
                isDescending = false;
                break;
            }
            n = m;
        }

        if (isDescending) {
            msg = "descending";
        }
    }

    cout << msg;
}