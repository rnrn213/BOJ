#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M, J;
    cin >> N >> M >> J;

    int left = 1, right = M, move = 0;
    for (int i = 0; i < J; i++) {
        int pos;
        cin >> pos;

        if (pos < left) {
            move += left - pos;
            left = pos;
            right = pos + M - 1;
        }
        else if (pos > right) {
            move += pos - right;
            left = pos - M + 1;
            right = pos;
        }
    }

    cout << move;
}