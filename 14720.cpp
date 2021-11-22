#include <bits/stdc++.h>

using namespace std;

int N;


int main() {
    cin >> N;

    int prev = -1, cnt = 0;
    for (int i = 0; i < N; i++) {
        int milk;
        cin >> milk;

        if ((prev == -1 || prev == 2) && milk == 0) {
            prev = 0;
            cnt++;
        }
        if (prev == 0 && milk == 1) {
            prev = 1;
            cnt++;
        }
        if (prev == 1 && milk == 2) {
            prev = 2;
            cnt++;
        }
    }

    cout << cnt;
}